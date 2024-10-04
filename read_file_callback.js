const fs = require('fs')
function read_file_1() {
  fs.readFile('./hello.txt', 'utf8', (err, data) => {
    if (err) {
      console.error(err)
      return
    }
    console.log(data)
  });
}

read_file_1();