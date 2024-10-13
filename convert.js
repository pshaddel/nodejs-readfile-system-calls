const fs = require('fs');

// first arg
const inputFile = process.argv[2];
// second arg
const outputFile = process.argv[3];

const data = fs.readFileSync(inputFile, 'utf-8');
const lines = data.split('\n');

const syscalls = [];
const calls = [];

lines.forEach(line => {
    // Skip header and separator lines
    if (line.startsWith('%') || line.startsWith('------')) {
        return;
    }

    // Assuming syscalls start at character position 40 and calls at 30
    const syscall = line.substring(40, 60).trim();
    const call = line.substring(30, 40).trim();

    if (syscall && call) {
        syscalls.push(syscall);
        calls.push(parseInt(call, 10));
    }
});

const result = {
    syscall: syscalls,
    calls: calls
};
// remove the output file if it exists
if (fs.existsSync(outputFile))
    fs.unlinkSync(outputFile);
fs.writeFileSync(outputFile, JSON.stringify(result, null, 2));
console.log('Output written to', outputFile);
