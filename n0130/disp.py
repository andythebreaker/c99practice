import tkinter as tk
from tkinter import ttk
from tkhtmlview import HTMLLabel

def display_svg(svg_code):
    root = tk.Tk()
    root.title("SVG Viewer")

    # Create a frame to hold the HTMLLabel
    frame = ttk.Frame(root)
    frame.pack(fill=tk.BOTH, expand=tk.YES)

    # Create an HTMLLabel and display the SVG code
    html_label = HTMLLabel(frame, html=svg_code)
    html_label.pack(fill=tk.BOTH, expand=tk.YES)

    root.mainloop()

# Example SVG code
example_svg = """
<svg width="100" height="100">
  <circle cx="50" cy="50" r="40" stroke="black" stroke-width="3" fill="red" />
</svg>
"""

# Call the function with the SVG code
display_svg(example_svg)
