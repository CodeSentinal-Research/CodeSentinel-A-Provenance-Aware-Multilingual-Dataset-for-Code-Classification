const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let arr = [];

rl.on('line', function(line) {
  arr.push(line.split(' '));
}).on('close', function() {
  const N = parseInt(arr[0][0]);
  const T = parseInt(arr[0][1]);
  let maxUnits = 0;

  for(let i = 1; i <= N; i++) {
    const boxes = parseInt(arr[i][0]);
    const units = parseInt(arr[i][1]);
    if(boxes + maxUnits <= T){
      maxUnits += boxes * units;
    }
    else{
      if(maxUnits < boxes * units){
        maxUnits = boxes * units;
      }
    }
  }

  console.log(maxUnits);

  rl.close();
});