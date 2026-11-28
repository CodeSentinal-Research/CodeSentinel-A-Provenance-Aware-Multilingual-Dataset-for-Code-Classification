Here is the JavaScript code:

process.stdin.setEncoding('ascii');
process.stdin.on('data', function(data) {
  var lineNr = 0;
  var lines = data.split('\n');
  for(var i = 0, len = lines.length; i < len; i++){
    if(i === 0){
      var N = Number(lines[i]);
      console.log(N);
    } else {
      var arr = lines[i].split(' ');
      var root = Number(arr[0]);
      var count = 0;
      for(var j = 1; j < arr.length; j++){
        var node = Number(arr[j]);
        if(node > root){
          count++;
        }
        root = node;
      }
      console.log(count);
    }
  }
});

This script reads the number of nodes N and then each node value. It checks if a node is greater than the root node and if so, increments the count. The root node is updated to the current node. The count is then printed out for each node.