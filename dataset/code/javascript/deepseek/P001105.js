function solve() {
  var fs = require('fs');
  process.stdin.resume();
  process.stdin.setEncoding('ascii');

  var input = fs.readFileSync('input.txt', 'utf8');
  input = input.split('\n');
  var N = parseInt(input[0]);
  var M = parseInt(input[1]);
  var prereqs = [];
  for (var i = 0; i < M; i++) {
    var pair = input[i + 2].split(' ');
    prereqs.push({ prereq: pair[0], course: pair[1] });
  }

  var graph = new Map();
  for (var i = 1; i <= N; i++) {
    graph.set(i, []);
  }

  for (var i = 0; i < M; i++) {
    graph.get(prereqs[i].course).push(prereqs[i].prereq);
  }

  var visited = new Array(N + 1).fill(false);
  var recStack = new Array(N + 1).fill(false);

  function isCyclic(course) {
    if (visited[course]) return false;
    if (recStack[course]) return true;

    visited[course] = true;
    recStack[course] = true;

    var neighbors = graph.get(course);
    for (var i = 0; i < neighbors.length; i++) {
      if (isCyclic(neighbors[i])) return true;
    }

    recStack[course] = false;
    return false;
  }

  for (var course = 1; course <= N; course++) {
    if (isCyclic(course)) {
      console.log('NO');
      return;
    }
  }

  console.log('YES');
}

solve();

This JavaScript solution uses a depth-first search (DFS) algorithm to detect cycles in the prerequisite graph. If any cycle is detected, it means that there is a cycle in the prerequisite relations, and we can't complete all courses because some courses depend on others that are already completed. If no cycle is detected, we can complete all courses.