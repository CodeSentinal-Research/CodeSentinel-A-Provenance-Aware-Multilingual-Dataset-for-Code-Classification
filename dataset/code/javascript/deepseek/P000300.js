Here is the JavaScript code to solve the problem:

function letterCombinations(digits) {
    if (digits === "") return [];
    let phone = {
        "2": ["a", "b", "c"],
        "3": ["d", "e", "f"],
        "4": ["g", "h", "i"],
        "5": ["j", "k", "l"],
        "6": ["m", "n", "o"],
        "7": ["p", "q", "r", "s"],
        "8": ["t", "u", "v"],
        "9": ["w", "x", "y", "z"],
    };
    let ans = [];
    function helper(index, str) {
        if (index === digits.length) {
            ans.push(str);
            return;
        }
        let chars = phone[digits[index]];
        for (let char of chars) {
            helper(index + 1, str + char);
        }
    }
    helper(0, "");
    return ans;
}

This function works by creating a phone object where each digit corresponds to an array of possible characters for that digit. The helper function is a recursive function that generates all possible combinations of the given digits and adds them to the answer array. It uses backtracking to ensure that no character is repeated.