const fs = require('fs');

function read_file_1() {
  try {
    const data = fs.readFileSync('./hello.txt', 'utf8');
    console.log(data);
  } catch (err) {
    console.error(err);
  }
}
read_file_1();