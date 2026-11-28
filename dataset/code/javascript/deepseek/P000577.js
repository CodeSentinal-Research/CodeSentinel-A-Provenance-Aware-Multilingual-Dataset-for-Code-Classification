function solve(root) {
    if (!root) return [];
  
    let queue = [root];
    let result = [];
    let map = new Map();
  
    while (queue.length > 0) {
        let node = queue.shift();
        let pos = map.get(node.data);
        if (!pos) pos = 0;
        map.set(node.data, pos);
        if (node.left) queue.push(node.left);
        if (node.right) queue.push(node.right);
    }
  
    let min = Number.MAX_SAFE_INTEGER;
    let max = Number.MIN_SAFE_INTEGER;
  
    for (let [key, value] of map.entries()) {
        if (value > max) max = value;
        if (value < min) min = value;
    }
  
    for (let i = min; i <= max; i++) {
        result.push(map.get(i));
    }
    return result;
}