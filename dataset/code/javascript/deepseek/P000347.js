Here is the JavaScript code for the problem:

function reverseStr(S, K) {
    S = S.split('');
    for (let i = 0; i < S.length; i += 2 * K) {
        let start = i;
        let end = Math.min(i + K, S.length);
        while (start < end) {
            let temp = S[start];
            S[start] = S[end - 1];
            S[end - 1] = temp;
            start++;
            end--;
        }
    }
    return S.join('');
}

You can test this function with the following code:

console.log(reverseStr('abcdefg', 2));  // 'bacdefg'
console.log(reverseStr('abcdefghijklmnopqrstuvw', 3));  // 'bacdefghijklmnopqrsuvw'