Sure, here is the JavaScript code for the problem:

process.stdin.setEncoding('ascii');
process.stdin.on('data', function(data) {
  var str = data.replace(/\n/g, '').replace(/\s/g, '').toLowerCase();
  var newStr = str.replace(/[^a-z0-9]/g, '');
  var reverseStr = newStr.split('').reverse().join('');
  if(str === reverseStr) {
    process.stdout.write('YES\n');
  } else {
    process.stdout.write('NO\n');
  }
});

This JavaScript code reads the input string from standard input (stdin), removes all non-alphanumeric characters and converts the string to lower case. It then compares the cleaned string with its reverse. If they are equal, it prints 'YES'; otherwise, it prints 'NO'.