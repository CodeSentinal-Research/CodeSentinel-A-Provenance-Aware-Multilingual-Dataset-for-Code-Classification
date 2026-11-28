function reverseSubstrings(s) {
    let stack = [];
    let result = '';

    for(let i = 0; i < s.length; i++) {
        if(s[i] === '(') {
            stack.push(i);
        } else if(s[i] === ')') {
            let start = stack.pop();
            let substring = s.slice(start + 1, i);
            let reversedSubstring = substring.split('').reverse().join('')
            result += s.slice(0, start) + reversedSubstring;
        } else {
            result += s[i];
        }
    }

    return result;
}

console.log(reverseSubstrings('example(test(this(that)))'));

This function works by iterating through the string and using a stack to track the starting indices of each pair of parentheses. When it encounters a '(', it pushes its index onto the stack. When it encounters a ')', it pops the index off the stack, slices the substring between the last and current '(' and ')' in the string, reverses the substring, and then concatenates the reversed substring to the end of the result string. Any other character is added to the result as is. The function finally returns the result.

The function works in O(n) time where n is the length of the string. It uses O(n) space to store the stack and the result string.