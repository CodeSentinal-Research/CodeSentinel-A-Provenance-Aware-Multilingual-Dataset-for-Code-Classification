// read input from stdin
const [N, M, K] = readline().split(' ').map(Number);
const num1 = readline();
const num2 = readline();

const mergeArrays = (arr1, arr2, K) => {
    let merged = [...arr1, ...arr2];
    merged.sort((a, b) => b - a);
    return merged.slice(0, K).join('');
};

console.log(mergeArrays(num1, num2, K));