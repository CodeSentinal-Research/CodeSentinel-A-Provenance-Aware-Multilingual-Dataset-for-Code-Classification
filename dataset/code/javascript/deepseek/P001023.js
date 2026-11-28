process.stdin.resume();
process.stdin.on('data', function(data) {
  var N = parseInt(data.toString().split('\n')[0]);
  var arr = data.toString().split('\n')[1].split(' ').map(Number);
  var i = parseInt(data.toString().split('\n')[2]);

  console.log(findParent(arr, i));

  process.stdin.pause();
});

function findParent(arr, i){
  if(i==1){
    return -1;
  }
  else{
    return arr[Math.floor((i-1)/2)];
  }
}