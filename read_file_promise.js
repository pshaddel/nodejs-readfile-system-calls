const fs = require('fs').promises;

async function read_file_1() {
  try {
    const data = await fs.readFile('./hello.txt', 'utf8');
    console.log(data);
  } catch (err) {
    console.error(err);
  }
}

read_file_1();