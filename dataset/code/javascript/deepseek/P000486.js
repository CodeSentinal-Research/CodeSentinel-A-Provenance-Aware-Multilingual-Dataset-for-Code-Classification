function largestRectangleArea(heights) {
    let maxArea = 0;
    let stack = [-1]; // stack for bars

    for (let i = 0; i < heights.length; i++) {
        while (stack[0] !== -1 && heights[i] < heights[stack[0]]) {
            let h = heights[stack.pop()];
            let w = i - stack[0] - 1;
            maxArea = Math.max(maxArea, h * w);
        }
        stack[0] = i;
    }

    while (stack[0] !== -1) {
        let h = heights[stack.pop()];
        let w = heights.length - stack[0] - 1;
        maxArea = Math.max(maxArea, h * w);
    }

    return maxArea;
}