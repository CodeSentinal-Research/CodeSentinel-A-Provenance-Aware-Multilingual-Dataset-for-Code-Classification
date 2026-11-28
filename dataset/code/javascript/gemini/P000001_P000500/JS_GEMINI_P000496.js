const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const arr = tokens.slice(1, 1 + n).map(BigInt);
        const MOD = 1000000007n;
        const prevLess = new Array(n).fill(-1);
        const nextLess = new Array(n).fill(n);
        let st = [];
        for (let i = 0; i < n; i++) {
            while (st.length > 0 && arr[st[st.length - 1]] >= arr[i]) st.pop();
            prevLess[i] = st.length > 0 ? st[st.length - 1] : -1;
            st.push(i);
        }
        st = [];
        // Process from right to left
        for (let i = n - 1; i >= 0; i--) {
            while (st.length > 0 && arr[st[st.length - 1]] > arr[i]) st.pop();
            nextLess[i] = st.length > 0 ? st[st.length - 1] : n;
            st.push(i);
        }
        let ans = 0n;
        for (let i = 0; i < n; i++) {
            const left = BigInt(i - prevLess[i]);
            const right = BigInt(nextLess[i] - i);
            ans = (ans + arr[i] * left * right) % MOD;
        }
        console.log(ans.toString());
    }
}
main();