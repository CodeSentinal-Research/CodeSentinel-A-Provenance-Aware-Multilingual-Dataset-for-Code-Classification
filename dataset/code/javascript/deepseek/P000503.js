function scoreParentheses(s) {
    let score = 0;
    let balance = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            balance++;
        } else {
            balance--;
        }
        score += balance;
    }

    return score;
}