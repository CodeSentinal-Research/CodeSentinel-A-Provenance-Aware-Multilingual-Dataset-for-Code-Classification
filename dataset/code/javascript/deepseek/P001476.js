Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of buildings: ', (numBuildings) => {
    rl.question('Enter the heights of the buildings: ', (buildingsHeights) => {
        let sum = 0;
        let leftMax = 0;
        let rightMax = 0;

        let left = 0;
        let right = numBuildings - 1;

        while (left < right) {
            if (buildingsHeights[left] < buildingsHeights[right]) {
                if (buildingsHeights[left] > leftMax)
                    leftMax = buildingsHeights[left];
                else
                    sum += leftMax - buildingsHeights[left];
                left++;
            } else {
                if (buildingsHeights[right] > rightMax)
                    rightMax = buildingsHeights[right];
                else
                    sum += rightMax - buildingsHeights[right];
                right--;
           
            }
        }

        console.log('Total units of rainwater trapped: ', sum);
        rl.close();
    });
});

In this code, we are first reading the number of buildings and the heights of each building from the input. We then initialize two pointers `left` and `right` to point at the start and end of the array, and two variables `leftMax` and `rightMax` to keep track of the maximum height we have seen so far in the left and right section of the array, respectively.

We then enter a loop that continues until `left` is less than `right`. If the height at `left` is less than the height at `right`, we update `leftMax` if it is less than the current height, else we add the difference to our total (`sum`). We then increment `left`.

If the height at `right` is less than `rightMax`, we update `rightMax`, else we add the difference to `sum`. We decrement `right`. This process is repeated until `left` is greater than `right`, at which point we have processed all the buildings.

The total units of rainwater trapped is stored in `sum` and is then printed to the console.