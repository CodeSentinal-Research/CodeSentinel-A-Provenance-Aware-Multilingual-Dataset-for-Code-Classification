Here is the JavaScript solution for the problem:

function checkPermutation(s1, s2) {
    if (s1.length !== s2.length) {
        return "No";
    }

    let count = new Array(26).fill(0);

    for (let i = 0; i < s1.length; i++) {
        count[s1.charAt(i) - 'a']++;
    }

    for (let i = 0; i < s2.length; i++) {
        count[s2.charAt(i) - 'a']--;
        if (count[s2.charAt(i) - 'a'] < 0) {
            return "No";
        }
    }

    return "Yes";
}

This solution uses a count array to keep track of the frequency of each character in the first string. Then it iterates over the second string, decrementing the count for each character as it encounters it. If any character's count ever goes below zero, we know it's not a permutation of the first string, and we return "No". Otherwise, if it makes it through the entire second string without returning "No", we return "Yes".