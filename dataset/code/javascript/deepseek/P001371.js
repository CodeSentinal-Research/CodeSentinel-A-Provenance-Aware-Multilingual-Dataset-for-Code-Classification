process.stdin.resume();
process.stdin.on('data', function(chunk) {
  var N = parseInt(chunk.toString().trim());
  var A = [];
  for (var i = 0; i < N; i++) {
      A.push(parseInt(process.stdin.readLine().trim()));
  }
  var Target = parseInt(process.stdin.readLine().trim());

  var result = twoSum(A, Target);
  console.log(result.join(' '));
});

function twoSum(A, Target) {
  var map = {};
  for(var i in A) {
      if(A[i] in map) {
          return [map[A[i]], i];
      }
      else {
          map[Target - A[i]] = i;
      }
  }
  return [-1];
}