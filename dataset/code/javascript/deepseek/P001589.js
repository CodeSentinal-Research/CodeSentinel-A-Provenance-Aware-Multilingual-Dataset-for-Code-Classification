Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of days: ', (N) => {
  rl.question('Enter the hours worked: ', (hours) => {
    let maxGap = 0;
    let maxGapCount = 0;
    let nonTiringDays = 0;
    let maxTiringDays = 0;
    let tiringDays = 0;
    let nonTiringDays = 0;
    let maxTiringDaysCount = 0;
    let maxNonTiringDaysCount = 0;

    for (let i = 0; i < N; i++) {
      if (hours[i] > 8) {
        tiringDays++;
      } else {
        nonTiringDays++;
      }
    }

    for (let i = 0; i < N; i++) {
      if (hours[i] > 8) {
        if (tiringDays === 0) {
          tiringDays++;
          nonTiringDays = 0;
        } else {
          nonTiringDays++;
        }
      } else {
        if (nonTiringDays === 0) {
          nonTiringDays++;
          tiringDays = 0;
        } else {
          tiringDays++;
        }
      }

      if (tiringDays - nonTiringDays > maxGap) {
        maxGap = tiringDays - nonTiringDays;
        maxGapCount = 1;
        maxTiringDays = tiringDays;
        maxTiringDaysCount = 1;
      } else if (tiringDays - nonTiringDays === maxGap) {
        maxGapCount++;
        maxTiringDays += tiringDays;
        maxTiringDaysCount++;
      } else {
        tiringDays = 0;
        nonTiringDays = 0;
      }
    }

    console.log(maxTiringDays - nonTiringDays);

    rl.close();
  });
});

This code reads the number of days and the hours worked for each day, and then computes the maximum length of the longest contiguous interval where the number of tiring days (hours > 8) is strictly greater than the number of non-tiring days.