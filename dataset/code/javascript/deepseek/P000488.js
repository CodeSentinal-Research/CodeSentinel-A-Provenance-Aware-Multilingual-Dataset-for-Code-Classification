Here's a JavaScript solution for the problem using dynamic programming:

function maximalRectangle(matrix) {
  if (matrix.length === 0) return 0;
  
  let maxArea = 0;
  let rowLen = matrix.length;
  let colLen = matrix[0].length;
  let height = new Array(colLen).fill(0);
  
  for (let i = 0; i < rowLen; i++) {
    for (let j = 0; j < colLen; j++) {
      if (matrix[i][j] === 1) {
        height[j] += 1;
      } else {
        height[j] = 0;
      }
    }
    maxArea = Math.max(maxArea, largestRectangleArea(height));
  }
  
  return maxArea;
}

function largestRectangleArea(height) {
  let stack = [];
  let maxArea = 0;
  
  for (let i = 0; i <= height.length; i++) {
    let h = height[i] === undefined ? 0 : height[i];
    while (stack.length !== 0 && (height[stack[stack.length - 1]] > h)) {
      let currHeight = height[stack.pop()];
      let currWidth = stack.length ? i - stack[stack.length - 1] - 1 : i;
      maxArea = Math.max(maxArea, currHeight * currWidth);
    }
    stack.push(i);
  }
  
  return maxArea;
}

In the solution, the `maximalRectangle` function first checks if the input matrix is empty, and returns 0 if it is. Then it uses a dynamic programming approach to find the maximum area in the matrix. It iterates over the matrix twice, and for each cell, it calculates the maximum area by iterating over the heights of the bars in the rectangle. The `largestRectangleArea` function is used in the `maximalRectangle` function to find the maximum area of a rectangle. It uses a stack to store the heights of the bars, and iterates over the heights. When a smaller height is found, it calculates the area of the rectangle, and updates the maximum area if the current area is larger.