Here's the JavaScript code to solve the given problem:

// reading inputs
const [N, arr, Q] = JSON.parse(process.argv[2]);
const nums = arr.split(' ').map(Number);

const queries = [];
for (let i = 0; i < Q; i++) {
    const [L, R] = process.argv[3 + i].split(' ').map(Number);
    queries.push({ L, R });
}

// function to count even numbers in a range
const countEvenNumbers = (nums, queries) => {
    const countArr = nums.map(num => num % 2 === 0 ? num : 0);

    for (const query of queries) {
        const [L, R] = query;
        const evenCount = countArr.slice(L, R + 1).filter(num => num % 2 === 0).length;
        console.log(evenCount);
    }
};

// calling function with nums and queries
countEvenNumbers(nums, queries);

The code takes the number of elements and the array elements as input and then it processes the queries to determine the count of even numbers in each range.

It uses a map function to create an array with counts of even numbers and then uses a forEach loop to process each query. It uses the filter method to get the numbers in the range and then uses the length property to count the even numbers.