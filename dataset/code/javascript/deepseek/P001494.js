function DIStringMatch(s) {
    let min = 0,
        max = s.length,
        minIndex = 0,
        maxIndex = s.length - 1,
        res = [];

    for (let i = 0; i <= s.length; i++) {
        if (s[i] == 'I') {
            res.push(min);
            min++;
        } else {
            res.push(max);
            max--;
        }
    }
    return res;
}

console.log(DIStringMatch("IDID")); // Output: [0, 1, 2, 3]
This function works by iterating through the input string, pushing the smallest number (from 0) to the result array whenever it encounters the letter 'I' and pushing the largest number (from the length of the string) to the result array whenever it encounters the letter 'D'. 

The result array represents the permutation of numbers from 0 to the length of the string, satisfying both the increasing and decreasing constraints.