const fs = require('fs');

// find files in src folder
const files = fs.readdirSync('./src');
// remove extension from file name
const fileNames = files.map(file => file.split('.')[0]);
console.log(fileNames);

for (const fileName of fileNames) {
    const file1Path = `./data/${fileName}_1_converted.json`;
    const file2Path = `./data/${fileName}_101_converted.json`;
    const outputFilePath = `./data/${fileName}_diff_converted.json`;
    // Read and parse the first JSON file
    const file1Data = JSON.parse(fs.readFileSync(file1Path, 'utf-8'));
    // Read and parse the second JSON file
    const file2Data = JSON.parse(fs.readFileSync(file2Path, 'utf-8'));

    // Calculate the difference for each element in the calls array
    // round to near integer value
    const callsDiff = file2Data.calls.map((call, index) => Math.round((call - file1Data.calls[index]) / 100));

    const result = {
        syscall: file1Data.syscall,
        calls: callsDiff
    };

    if (fs.existsSync(outputFilePath))
        fs.unlinkSync(outputFilePath);
    fs.writeFileSync(outputFilePath, JSON.stringify(result, null, 2));
}
