function compress(chars) {
    let write = 0, read = 0, n = chars.length;

    while (read < n) {
        const ch = chars[read];
        let count = 0;
        while (read < n && chars[read] === ch) {
            read++;
            count++;
        }

        chars[write++] = ch;

        if (count > 1) {
            for (const c of String(count)) {
                chars[write++] = c;
            }
        }
    }
    return write;
}

module.exports = { compress };