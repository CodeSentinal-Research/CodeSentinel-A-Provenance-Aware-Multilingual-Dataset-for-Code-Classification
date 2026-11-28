Here is the JavaScript code for the task scheduler with cooling time problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let tasks = [];

rl.on('line', function(line) {
    if (tasks.length == 0) {
        tasks = line.split(' ');
    } else if (tasks.length == 1) {
        let k = parseInt(line);
        // cooling time loop
        while(true) {
            let cool = true;
            for (let i = 0; i < tasks.length; i++) {
                if (tasks[i] > 0) {
                    cool = false;
                    tasks[i]--;
                    break;
                }
            }
            if (cool) {
                console.log(k);
                break;
            }
        }
    }
});

rl.close();
This code reads the input line by line. The first line is read and stored in the array `tasks`. If it's the second line, the cooling time loop starts. In each loop, it checks if any task remains to be executed. If it finds a task that has not finished executing, it decreases the execution time for that task by 1 and continues. If it doesn't find any tasks that have remaining execution time, it breaks the loop and prints the cooling time. The loop will continue until all tasks have finished executing.