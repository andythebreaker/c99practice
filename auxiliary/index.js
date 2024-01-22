const puppeteer = require('puppeteer');
const fs = require('fs');

(async () => {
  // Launch a headless browser
  const browser = await puppeteer.launch({ headless: true });

  // Create a new page
  const page = await browser.newPage();

  // Navigate to the URL
  await page.goto('https://akb48-tp.tenten.tw/', { waitUntil: 'domcontentloaded' });

  // Wait for a certain amount of time or for a specific element to be present if necessary
  // You can customize this based on the website's behavior
  await page.waitForTimeout(5000);

  // Get the page content (fully loaded HTML)
  const html = await page.content();

  // Save the HTML to a file
  fs.writeFileSync('akb48-tp.html', html, 'utf-8');

  // Close the browser
  await browser.close();

  console.log('HTML saved successfully!');
})();
