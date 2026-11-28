let [n, ...buildings] = require('fs').readFileSync(0).toString().trim().split(' ');
let [bricks, ladders] = require('fs').readFileSync(1).toString().trim().split(' ');

function furthestReachableBuilding(n, buildings, bricks, ladders) {
  // Initialize variables
  let maxHeight = Math.max(...buildings);
  let bricksLeft = bricks;
  let laddersUsed = 0;
  let maxBuildingIndex = 0;

  // Iterate over buildings from left to right
  for(let i = 0; i < n; i++) {
    if(buildings[i] > maxHeight) {
      maxHeight = buildings[i];
    }
    // Use bricks if possible
    while(bricksLeft > 0 && buildings[i] > maxHeight && bricksLeft > 0) {
      bricksLeft--;
    }
    // Use ladders if possible
    while(laddersUsed < ladders && i < n-1 && buildings[i+1] >= maxHeight-1) {
      laddersUsed++;
      i++;
    }
  }

  // Return the index of the furthest reachable building
  return maxBuildingIndex;
}

console.log(furthestReachableBuilding(n, buildings, bricks, ladders));

This JavaScript solution uses a greedy approach. It iterates over the buildings from left to right, using bricks if possible and ladders if possible. The index of the furthest reachable building is returned at the end.

Please note that the above code requires two files as input: one for the number of buildings, the other for the heights of the buildings. The first line of each file contains the number of buildings, followed by the heights of the buildings.

Here is how you can run the code:

1. Save the above code in a file named `furthestReachableBuilding.js`.
2. Open a terminal or command prompt and navigate to the directory where you saved the file.
3. Run the command `node furthestReachableBuilding.js`.

Please replace `furthestReachableBuilding.js` with your actual file name and make sure to place two files named `input1` and `input2` in the same directory as your JavaScript file.