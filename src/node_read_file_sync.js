const fs = require('fs');
fs.promises.readFile
function read_file_1() {
  try {
    // get the number of times we should repeat the read operation
    const repeat = process.argv[2] || 1;
    for (let i = 0; i < repeat; i++) {
      const data = fs.readFileSync('./hello.txt', 'utf8');
      console.log(data);
    }
  } catch (err) {
    console.error(err);
  }
}
read_file_1();