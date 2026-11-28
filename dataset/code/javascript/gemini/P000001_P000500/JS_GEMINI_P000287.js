function reverseVowels(s) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    const arr = s.split('');
    let i = 0, j = arr.length - 1;
    while (i < j) {
        if (!vowels.has(arr[i])) i++;
        else if (!vowels.has(arr[j])) j--;
        else {
            const temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            i++; j--;
        }
    }
    return arr.join('');
}

module.exports = { reverseVowels };