function unionOfArrays() {
  var inputs = process.argv.slice(2);
  var m = parseInt(inputs[0]);
  var arr1 = inputs[1].split(' ').map(Number);
  var n = parseInt(inputs[2]);
  var arr2 = inputs[3].split(' ').map(Number);

  var set1 = new Set(arr1);
  var set2 = new Set(arr2);

  var union = [...set1, ...set2];
  var result = Array.from(union);
  result.sort(function(a, b) {
    return a - b;
  });
  
  console.log(result.join(' '));
}

unionOfArrays();
This JavaScript function uses Node.js's `process.argv` to handle command line arguments. The input data is split into two parts and mapped to array objects for processing. The union of these two arrays is then printed to the console in a sorted manner.