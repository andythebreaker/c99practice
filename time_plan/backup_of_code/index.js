const cheerio = require('cheerio');
const iconv = require('iconv-lite');
const fs = require('fs').promises;

async function main(a,b) {
  const response = await fetchXXX;

  const buffer = await response.arrayBuffer();
  const decoded = iconv.decode(Buffer.from(buffer), 'big5');

  // Save to a text file
  try {
    await fs.writeFile(`${a}0${b<10?("0"+String(b)):String(b)}.txt`, decoded);
    console.log(`Content saved to ${a}0${b<10?("0"+String(b)):String(b)}.txt`);
  } catch (error) {
    console.error('Error saving content to file:', error);
  }
}

async function master(){
    //await main(a,b); //a = 1, b=1~26
    for (let i = 1; i <= 26; i++) {
        await main(1,i);
    }
    //a=2, b=1~23
    for (let i = 1; i <= 23; i++) {
        await main(2,i);
    }
    //a=3, b=1~25
    for (let i = 1; i <= 25; i++) {
        await main(3,i);
    }
}

master();

