function minSubstring(S, T) {
    if (S.length === 0 || T.length === 0) return "";

    let result = "", minLength = Infinity;

    for (let i = 0; i < S.length; i++) {
        let j = i;
        let count = 0;
        while (S[j] === T[count]) {
            count++;
            j++;
            if (count === T.length) {
                if (j - i + 1 < minLength) {
                    minLength = j - i + 1;
                    result = S.substring(i, j + 1);
                }
                break;
            }
        }
    }

    return result;
}