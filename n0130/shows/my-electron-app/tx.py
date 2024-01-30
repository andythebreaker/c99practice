import subprocess
import base64
import tkinter as tk
import os

def generate_svg(table):
    svg_code = f'<svg width="{5*50}" height="{5*50}" xmlns="http://www.w3.org/2000/svg">\n'
    
    # Define cell size and padding
    svg_code += '    <defs>\n      <style>\n        .cell { width: 50px; height: 50px; }\n'
    svg_code += '        .border { stroke: black; stroke-width: 2; fill: none; }\n      </style>\n'
    svg_code += '    </defs>\n\n'

    # Draw table cells and borders
    for cell in table:
        x = cell["x"] * 50
        y = cell["y"] * 50
        color = cell["color"]
        svg_code += f'    <rect x="{x}" y="{y}" class="cell" fill="{color}"/>\n'
    
    # Draw borders based on the provided data
    for i in range(len(table)):
        x1 = table[i]["x"] * 50
        y1 = table[i]["y"] * 50

        if table[i]["n"]:
            svg_code += f'    <line x1="{x1}" y1="{y1}" x2="{x1 + 50}" y2="{y1}" class="border"/>\n'
        if table[i]["e"]:
            svg_code += f'    <line x1="{x1 + 50}" y1="{y1}" x2="{x1 + 50}" y2="{y1 + 50}" class="border"/>\n'
        if table[i]["s"]:
            svg_code += f'    <line x1="{x1}" y1="{y1 + 50}" x2="{x1 + 50}" y2="{y1 + 50}" class="border"/>\n'
        if table[i]["w"]:
            svg_code += f'    <line x1="{x1}" y1="{y1}" x2="{x1}" y2="{y1 + 50}" class="border"/>\n'

    svg_code += '  </svg>'
    return svg_code

def on_generate_svg():
    input_text = input_textbox.get("1.0", "end-1c")
    try:
        input_data = eval(input_text)
        svg_output = generate_svg(input_data["table"])
        output_textbox.delete("1.0", "end")
        output_textbox.insert("1.0", svg_output)
        # svg_output -> base64
        encoded_bytes = base64.b64encode(svg_output.encode('utf-8'))
        print(str(encoded_bytes)[2:-1])
        # cmd npm start encoded_bytes
        
        # Get the current working directory
        current_dir = os.getcwd()

        # Change directory using subprocess
        subprocess.run(['cd', current_dir], shell=True, check=True)

        # Run npm start using subprocess
        subprocess.run(['npm', 'start',str(encoded_bytes)[2:-1]], shell=True, check=True)

    except Exception as e:
        output_textbox.delete("1.0", "end")
        output_textbox.insert("1.0", f"Error: {str(e)}")

# Create the main window
window = tk.Tk()
window.title("SVG Generator")

# Input Textbox
input_textbox = tk.Text(window, height=60, width=200)
input_textbox.insert("1.0", 'Enter JSON input here...')
input_textbox.pack()

# Generate SVG Button
generate_button = tk.Button(window, text="Generate SVG", command=on_generate_svg)
generate_button.pack()

# Output Textbox
output_textbox = tk.Text(window, height=20, width=60)
output_textbox.insert("1.0", 'SVG Output will be displayed here...')
output_textbox.pack()

# Start the main loop
window.mainloop()
