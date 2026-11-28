function find_difference(N, arr1, M, arr2) {
  let set1 = new Set(arr1);
  let set2 = new Set(arr2);

  let uniqueInFirst = Array.from(set1).filter(value => !set2.has(value));
  let uniqueInSecond = Array.from(set2).filter(value => !set1.has(value));

  uniqueInFirst.sort((a, b) => a - b);
  uniqueInSecond.sort((a, b) => a - b);

  console.log(uniqueInFirst.join(' '));
  console.log(uniqueInSecond.join(' '));
}

process.stdin.on('data', (data) => {
  const [N, arr1, M, arr2] = data.toString().trim().split(' ').map(item => parseInt(item, 10));

  find_difference(N, arr1, M, arr2);
});

This JavaScript code will take inputs from standard input and calculate the difference of two arrays. Input will be handled in the following way:

- First line contains two integers N and M, which represent the number of elements in the first array and the second array respectively.
- Second line contains N integers, which represent elements in the first array.
- Third line contains M integers, which represent elements in the second array.

The code will then calculate and print the difference of two arrays in sorted order.