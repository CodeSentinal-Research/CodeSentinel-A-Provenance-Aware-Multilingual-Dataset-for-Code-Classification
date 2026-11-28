const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const h = tokens.slice(1, 1 + n).map(BigInt);
        const left = new Array(n).fill(0n);
        const right = new Array(n).fill(0n);
        let st = [];
        for (let i = 0; i < n; i++) {
            while (st.length > 0 && h[st[st.length - 1]] >= h[i]) st.pop();
            left[i] = st.length === 0 ? h[i] * BigInt(i + 1) : left[st[st.length - 1]] + h[i] * BigInt(i - st[st.length - 1]);
            st.push(i);
        }
        st = [];
        // Process from right to left
        for (let i = n - 1; i >= 0; i--) {
            while (st.length > 0 && h[st[st.length - 1]] >= h[i]) st.pop();
            right[i] = st.length === 0 ? h[i] * BigInt(n - i) : right[st[st.length - 1]] + h[i] * BigInt(st[st.length - 1] - i);
            st.push(i);
        }
        let maxSum = 0n;
        for (let i = 0; i < n; i++) {
            const cur = left[i] + right[i] - h[i];
            if (cur > maxSum) maxSum = cur;
        }
        console.log(maxSum.toString());
    }
}
main();