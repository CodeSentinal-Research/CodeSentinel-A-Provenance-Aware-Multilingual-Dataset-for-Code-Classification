process.stdin.resume();
process.stdin.on('data', function(data) {
  var str = data.toString().trim();
  var n = parseInt(process.stdin.readLine().toString().trim());
  var arr = [];
  for(var i = 0; i < n; i++) {
    arr.push(process.stdin.readLine().toString().trim());
  }
  process.stdout.write(solve(str, arr) + "\n");
});

function solve(str, arr) {
  var count = 0;
  for(var i = 0; i < arr.length; i++) {
    if(isSubsequence(arr[i], str)) {
      count++;
    }
  }
  return count;
}

function isSubsequence(str, sub) {
  var i = 0, j = 0;
  while(i < str.length && j < sub.length) {
    if(str[i] == sub[j]) {
      j++;
    }
    i++;
  }
  return j == sub.length;
}