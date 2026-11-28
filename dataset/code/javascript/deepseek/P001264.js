process.stdin.setEncoding('utf8');

process.stdin.on('data', function(data) {
  var numTasks = parseInt(data);
  var tasks = [];

  for(var i = 0; i < numTasks; i++) {
    var task = process.stdin.readLine().split(' ');
    tasks.push({
      energy: parseInt(task[0]),
      minEnergy: parseInt(task[1])
    });
  }

  tasks.sort(function(a, b) {
    return a.minEnergy - b.minEnergy;
  });

  var totalEnergy = 0;
  var minEnergy = Number.MAX_SAFE_INTEGER;

  for(var i = 0; i < numTasks; i++) {
    if (tasks[i].minEnergy >= minEnergy) {
      minEnergy = tasks[i].minEnergy;
    } else {
      totalEnergy += minEnergy - tasks[i].minEnergy;
    }
  }

  console.log(totalEnergy);
});

This JavaScript program reads the number of tasks from the standard input, then reads each task's energy and minimum energy from the standard input. It stores these tasks in an array. The array is sorted based on the minimum energy of each task. It then iterates through the sorted array, adding the difference between the minimum energy of the current task and the minimum energy of the previous tasks to a total energy. The minimum energy is updated whenever a task with a higher minimum energy is found. Finally, it prints the total energy.