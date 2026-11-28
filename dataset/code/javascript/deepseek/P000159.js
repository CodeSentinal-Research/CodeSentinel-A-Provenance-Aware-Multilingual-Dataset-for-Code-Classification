process.stdin.setEncoding('utf8');
process.stdin.on('data', function(input){
  var arr = input.split('\n');
  var n = parseInt(arr[0]);
  var a = arr[1].split(' ').map(Number);
  var minSum = a[0];
  var maxSum = a[0];
  var minStart = 0;
  var minEnd = 0;
  var maxStart = 0;
  var maxEnd = 0;

  for(var i = 1; i < n; i++){
    var curr = a[i];
    if(a[i-1] > 0){
      a[i] += a[i-1];
    }
    if(a[i] < minSum){
      minSum = a[i];
      minEnd = i;
    }
    if(a[i] > maxSum){
      maxSum = a[i];
      maxEnd = i;
    }
  }

  console.log(`Min sum: ${minSum} at indices ${minStart}-${minEnd}`);
  console.log(`Max sum: ${maxSum} at indices ${maxStart}-${maxEnd}`);
});