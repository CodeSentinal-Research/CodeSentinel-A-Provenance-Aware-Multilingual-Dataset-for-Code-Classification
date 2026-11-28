function reverseVowels(s) {
    const vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
    let left = 0;
    let right = s.length - 1;
    const arr = Array.from(s);
    while (left < right) {
        if (!vowels.includes(arr[left])) {
            left++;
        } else if (!vowels.includes(arr[right])) {
            right--;
        } else {
            [arr[left], arr[right]] = [arr[right], arr[left]];
            left++;
            right--;
        }
    }
    return arr.join('');
}

console.log(reverseVowels('hello')); // 'holle'
console.log(reverseVowels('world')); // 'wrdlo'