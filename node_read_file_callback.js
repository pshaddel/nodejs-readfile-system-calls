const fs = require('fs');

function read_file_1(repeat, count = 0) {
  if (count >= repeat) return;

  fs.readFile('./hello.txt', 'utf8', (err, data) => {
    if (err) {
      console.error(err);
      return;
    }
    console.log(data);
    read_file_1(repeat, count + 1); // Call the function recursively
  });
}

// Get the number of times we should repeat the read operation
const repeat = parseInt(process.argv[2], 10) || 1;

read_file_1(repeat);