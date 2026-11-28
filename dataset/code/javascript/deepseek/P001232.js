Here is the JavaScript code for the problem:

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of activities: ', (n) => {
  rl.setPrompt('Enter start time and finish time: ');

  let startTimes = [];
  let endTimes = [];

  for(let i = 0; i < n; i++) {
    rl.prompt();
  }

  rl.on('line', (line) => {
    let [start, end] = line.split(' ');
    startTimes.push(parseInt(start));
    endTimes.push(parseInt(end));

    if(startTimes.length == n) {
      rl.close();
    }
  });

  let selectedActivities = 0;
  let currentEndTime = 0;

  startTimes.forEach((startTime, index) => {
    if(startTime >= currentEndTime) {
      selectedActivities++;
      currentEndTime = endTimes[index];
    }
  });

  console.log(selectedActivities);
});

In this code, the readline module is used to handle the input. The readline.createInterface() function is used to create a readline interface where input is read from the process.stdin stream and the output is written to the process.stdout stream. The readline interface uses a simple prompt mechanism to ask for the user's input. The line event is an event that fires for each line of input read from the stream.

When the line event is triggered, the code splits the line into start and end times and pushes them into the startTimes and endTimes arrays respectively. If the length of startTimes is equal to n (the number of activities), it means we have all the input, so we close the readline interface. If the start time is greater than or equal to the current end time, it means an activity can be selected, so we increment the selectedActivities counter and update the current end time.

Finally, the selectedActivities counter is logged to the console.