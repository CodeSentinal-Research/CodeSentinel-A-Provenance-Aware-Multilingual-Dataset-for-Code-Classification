const fs = require('fs');
function largestArea(heights) {
    const h = [...heights, 0];
    const st = [-1];
    let maxArea = 0;
    for (let i = 0; i < h.length; i++) {
        while (st.length > 1 && h[st[st.length - 1]] >= h[i]) {
            const height = h[st.pop()];
            const w = i - st[st.length - 1] - 1;
            maxArea = Math.max(maxArea, height * w);
        }
        st.push(i);
    }
    return maxArea;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const r = parseInt(tokens[0], 10), c = parseInt(tokens[1], 10);
        let idx = 2;
        const heights = new Array(c).fill(0);
        let maxArea = 0;
        for (let i = 0; i < r; i++) {
            for (let j = 0; j < c; j++) {
                const val = Number(tokens[idx++]);
                heights[j] = (val === 1) ? heights[j] + 1 : 0;
            }
            maxArea = Math.max(maxArea, largestArea(heights));
        }
        console.log(maxArea);
    }
}
main();