Here's a simple JavaScript code solution for the problem:

process.stdin.setEncoding('utf8');
process.stdin.on('data', (data) => {
    let [str, pattern] = data.split('\n');
    pattern = pattern.split('').map(c => c.replace(/([.^\*])/g, '\\$1')).join('');
    let regex = new RegExp(pattern);
    console.log(regex.test(str) ? 'YES' : 'NO');
});

This code reads the text string and pattern from standard input, then uses the RegExp constructor to compile the pattern into a regular expression. Finally, it uses the test() method to test if the pattern matches the entire string.

Please note that this is a very simple implementation and may not work with complex patterns or large strings. For such cases, you may need to use a more sophisticated regular expression parser or a library that can handle such cases.