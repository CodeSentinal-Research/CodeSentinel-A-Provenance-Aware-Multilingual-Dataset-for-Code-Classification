Here is a simple JavaScript solution for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of bars: ', (bars) => {
    rl.question('Enter the heights of each bar: ', (barHeights) => {
        const heights = barHeights.split(' ').map(Number);

        let totalWater = 0;
        let leftMax = 0;
        let rightMax = 0;

        let left = 0;
        let right = heights.length - 1;

        while (left < right) {
            if (heights[left] < heights[right]) {
                if (heights[left] > leftMax) {
                    leftMax = heights[left];
                } else {
                    totalWater += leftMax - heights[left];
                }
                left++;
            } else {
                if (heights[right] > rightMax) {
                    rightMax = heights[right];
                } else {
                    totalWater += rightMax - heights[right];
                }
                right--;
            }
        }

        console.log(totalWater);
        rl.close();
    });
});

This code reads the number of bars and the heights of each bar from the input. It then calculates the maximum height it can trap with the left and right bars. The total trapped water is then calculated by subtracting the current bar's height from the maximum height it can trap in the current direction. This process is repeated until all bars have been checked.