const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const heights = tokens.slice(1, 1 + n).map(Number);
        heights.push(0);
        const st = [-1];
        let maxArea = 0;
        for (let i = 0; i <= n; i++) {
            while (st.length > 1 && heights[st[st.length - 1]] >= heights[i]) {
                const h = heights[st.pop()];
                const w = i - st[st.length - 1] - 1;
                maxArea = Math.max(maxArea, h * w);
            }
            st.push(i);
        }
        console.log(maxArea);
    }
}
main();