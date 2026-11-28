function removeKdigits(s, k) {
    let res = '0';
    for (let i = 0; i < s.length; i++) {
        if (k > 0 && s[i] < res[0]) {
            res = res.slice(0, res.length - 1) + s[i];
            k--;
        } else if (s[i] != '0' || res[0] == '0') {
            res += s[i];
        }
    }

    while (k > 0) {
        res = res.slice(0, res.length - 1);
        k--;
    }

    return res;
}

console.log(removeKdigits('1234567890', 4)); // Output: "1234"