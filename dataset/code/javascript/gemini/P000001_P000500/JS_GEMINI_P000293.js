class Codec {
    encode(strs) {
        let res = "";
        for (const s of strs) {
            res += `${s.length}#${s}`;
        }
        return res;
    }

    decode(s) {
        const res = [];
        let i = 0;
        while (i < s.length) {
            const j = s.indexOf('#', i);
            const len = parseInt(s.substring(i, j), 10);
            res.push(s.substring(j + 1, j + 1 + len));
            i = j + 1 + len;
        }
        return res;
    }
}

module.exports = { Codec };