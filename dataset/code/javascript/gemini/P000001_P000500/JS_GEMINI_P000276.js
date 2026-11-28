function countAndSay(n) {
    let s = "1";
    for (let step = 1; step < n; step++) {
        let nextS = "";
        let i = 0;
        while (i < s.length) {
            let count = 1;
            while (i + 1 < s.length && s[i] === s[i + 1]) {
                i++;
                count++;
            }
            nextS += count + s[i];
            i++;
        }
        s = nextS;
    }
    return s;
}

module.exports = { countAndSay };