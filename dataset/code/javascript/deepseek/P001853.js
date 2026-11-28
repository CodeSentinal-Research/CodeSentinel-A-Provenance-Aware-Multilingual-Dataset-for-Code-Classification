Here is the JavaScript code for the problem:

let fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_filename = process.argv[2] || process.stdin;
var output_filename = process.argv[3] || process.stdout;

var readable = fs.createReadStream(input_filename);
var writable = fs.createWriteStream(output_filename);

readable
    .pipe(new StringDecoder('utf8'))
    .pipe(writable);

process.stdin.on('end', function() {
    console.log('Input has ended');
    process.stdin.close();
});


You can use this code to solve the problem, by reading the input from the console and writing the output to the console. Replace 'input.txt' and 'output.txt' with the filenames of your input and output files.