function maxArea(M, n, m) {
    function largestHist(heights) {
        const stack = [];
        let maxArea = 0;
        const len = heights.length;

        for (let i = 0; i <= len; i++) {
            const h = i === len ? 0 : heights[i];
            // Maintain monotonic stack property by popping smaller elements
            while (stack.length && heights[stack[stack.length - 1]] > h) {
                const top = stack.pop();
                const w = stack.length === 0 ? i : i - stack[stack.length - 1] - 1;
                const area = heights[top] * w;
                if (area > maxArea) maxArea = area;
            }
            stack.push(i);
        }
        return maxArea;
    }

    const heights = new Array(m).fill(0);
    let maxRect = 0;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            heights[j] = M[i][j] === 1 ? heights[j] + 1 : 0;
        }
        const area = largestHist(heights);
        if (area > maxRect) maxRect = area;
    }

    return maxRect;
}

module.exports = { maxArea };