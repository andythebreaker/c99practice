// // main.js

// // Modules to control application life and create native browser window
// const { app, BrowserWindow } = require('electron')
// const path = require('node:path')

// const createWindow = () => {
//   // Create the browser window.
//   const mainWindow = new BrowserWindow({
//     width: 800,
//     height: 600,
//     webPreferences: {
//       preload: path.join(__dirname, 'preload.js')
//     }
//   })

//   // and load the index.html of the app.
//   mainWindow.loadFile('index.html')

//   // Open the DevTools.
//   // mainWindow.webContents.openDevTools()
// }

// // This method will be called when Electron has finished
// // initialization and is ready to create browser windows.
// // Some APIs can only be used after this event occurs.
// app.whenReady().then(() => {
//   createWindow()

//   app.on('activate', () => {
//     // On macOS it's common to re-create a window in the app when the
//     // dock icon is clicked and there are no other windows open.
//     if (BrowserWindow.getAllWindows().length === 0) createWindow()
//   })
// })

// // Quit when all windows are closed, except on macOS. There, it's common
// // for applications and their menu bar to stay active until the user quits
// // explicitly with Cmd + Q.
// app.on('window-all-closed', () => {
//   if (process.platform !== 'darwin') app.quit()
// })

// // In this file you can include the rest of your app's specific main process
// // code. You can also put them in separate files and require them here.

const { app, BrowserWindow } = require('electron');
const path = require('path');

function createWindow() {
  // Create the browser window.
  const mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js')
    }
  });

  // Get the command line arguments
  const args = process.argv.slice(2);

  // Check if there is a base64 string passed as an argument
  if (args.length > 0) {
    const base64String = args[0];
    
    // Decode the base64 string to HTML
    const htmlString = Buffer.from(base64String, 'base64').toString('utf-8');

    // Load the HTML content into the main window
    mainWindow.loadURL(`data:text/html;charset=utf-8,${encodeURIComponent(htmlString)}`);
  } else {
    // If no base64 string is provided, load a default HTML file or do nothing
    mainWindow.loadFile('index.html');
  }

  // Open the DevTools.
  // mainWindow.webContents.openDevTools()
}

// Create the main window when the app is ready
app.whenReady().then(() => {
  createWindow();

  app.on('activate', function () {
    if (BrowserWindow.getAllWindows().length === 0) createWindow();
  });
});

// Quit the app when all windows are closed (except on macOS)
app.on('window-all-closed', function () {
  if (process.platform !== 'darwin') app.quit();
});
