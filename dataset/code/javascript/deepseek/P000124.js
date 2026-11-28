Here is the JavaScript code for the problem:

process.stdin.setEncoding('utf8');
process.stdin.on('data', function(input) {
  var N = parseInt(input);
  var arr = [];
  process.stdin.on('data', function(input) {
    arr.push(parseInt(input));
    if (arr.length === N) {
      process.stdout.write(productArray(arr) + '\n');
    }
  });
});

function productArray(arr) {
  var product = [1];
  for (var i = 0; i < arr.length; i++) {
    product[i] = product[i - 1] * arr[i];
  }
  product[0] = product[1];
  for (var i = product.length - 1; i > 0; i--) {
    product[i] = product[i] * product[i - 1];
  }
  return product.join(' ');
}

In this code, we read the first line as the number of elements in the array, and then read the elements one by one. We keep adding them to an array `arr`. When the length of `arr` reaches the number of elements we input, we calculate the product array and print it.

We use the `productArray` function to calculate the product array. It first creates a product array `product` with a single element `1` (since the product of all numbers is 1). Then, for each element in `arr`, we update `product[i]` by multiplying `product[i - 1]` and `arr[i]`. After that, we update `product[i]` by multiplying `product[i]` and `product[i - 1]`. Finally, we return the product array joined by spaces.