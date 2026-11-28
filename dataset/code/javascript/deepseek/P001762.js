let nodes = {
  "-1": {
    sum: -Infinity,
    minSumChild: "-1",
    minSumRoot: "-1",
  },
};

let id = 0;
function solve(tree) {
  if (nodes[tree].sum !== -Infinity) {
    return nodes[tree].sum;
  }
  if (nodes[tree].minSumChild === "-1") {
    nodes[tree].minSumChild = id++;
  }
  if (nodes[nodes[tree].minSumChild].minSumRoot === "-1") {
    nodes[nodes[tree].minSumChild].minSumRoot = id++;
  }
  let leftChild = tree + "-" + nodes[tree].minSumChild;
  let rightChild = tree + "-" + nodes[tree].minSumChild;
  nodes[tree].sum = nodes[nodes[tree].minSumChild].sum + nodes[tree].sum;
  if (nodes[leftChild].sum > nodes[rightChild].sum) {
    nodes[tree].minSumRoot = nodes[rightChild].minSumRoot;
  } else {
    nodes[tree].minSumRoot = nodes[leftChild].minSumRoot;
  }
  return nodes[tree].sum;
}

function main() {
  let N = parseInt(readline());
  for (let i = 0; i < N; i++) {
    let line = readline().split(" ");
    let tree = line[0] + "-" + line[1];
    nodes[tree] = {
      sum: parseInt(line[2]),
      minSumChild: "-1",
      minSumRoot: "-1",
    };
  }
  console.log(solve("0-0"));
}