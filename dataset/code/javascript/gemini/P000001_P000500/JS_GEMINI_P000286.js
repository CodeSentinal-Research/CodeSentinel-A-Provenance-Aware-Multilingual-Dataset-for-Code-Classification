function reverseOnlyLetters(s) {
    const arr = s.split('');
    let i = 0, j = arr.length - 1;
    while (i < j) {
        if (!/[a-zA-Z]/.test(arr[i])) i++;
        else if (!/[a-zA-Z]/.test(arr[j])) j--;
        else {
            const temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            i++; j--;
        }
    }
    return arr.join('');
}

module.exports = { reverseOnlyLetters };