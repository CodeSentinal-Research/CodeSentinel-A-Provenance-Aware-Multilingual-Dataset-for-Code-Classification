Here is the JavaScript code to solve the Activity Selection Problem:

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = parseInt(rl.question());
rl.close();

let start = [];
let finish = [];

for(let i = 0; i < N; i++) {
  start[i] = parseInt(rl.question());
}

for(let i = 0; i < N; i++) {
  finish[i] = parseInt(rl.question());
}

let selectedActivities = 0;
let i = 0;

while (i < N) {
  if (i === 0 || finish[i] > start[i-1]) {
    selectedActivities++;
    i++;
  } else {
    i++;
  }
}

console.log(selectedActivities);

This code reads the number of activities N and then reads the start and end times for each activity. It then initializes a counter for the number of selected activities and a pointer for traversing the activities. The code checks if the current activity can start after the last selected activity and if so, selects the current activity and moves the pointer. Otherwise, it just moves the pointer to the next activity. The number of selected activities is then printed to the console.