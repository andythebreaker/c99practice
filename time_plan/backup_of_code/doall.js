const fs = require('fs');
const { exec } = require('child_process');

// Get a list of all .txt files in the current directory
const txtFiles = fs.readdirSync('.', { withFileTypes: true })
  .filter(file => file.isFile() && file.name.endsWith('.txt'))
  .map(file => file.name);

// Function to execute the command for each file
const executeCommand = (fileName) => {
  const command = `phrase_schedule.exe ${fileName}`;

  exec(command, (error, stdout, stderr) => {
    if (error) {
      console.error(`Error executing command for ${fileName}: ${error.message}`);
      return;
    }

    if (stderr) {
      console.error(`Command stderr for ${fileName}: ${stderr}`);
    }

    //console.log(`Output for ${fileName}:\n`);
    console.log(`${stdout}`);
  });
};

// Execute the command for each .txt file
txtFiles.forEach(executeCommand);
