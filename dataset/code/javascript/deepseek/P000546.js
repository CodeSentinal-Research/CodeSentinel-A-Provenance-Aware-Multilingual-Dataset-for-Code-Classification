Sure, here is the JavaScript solution for the problem:

function canReach(s, minJump, maxJump) {
    let queue = [0];
    let n = s.length;
    let visited = new Array(n).fill(false);
    visited[0] = true;
    
    while (queue.length) {
        let idx = queue.shift();
        
        for (let nextIdx of [idx - minJump, idx - maxJump, idx + minJump, idx + maxJump]) {
            if (nextIdx < 0 || nextIdx >= n || s[nextIdx] === '1' || visited[nextIdx]) {
                continue;
            }
            
            if (nextIdx === n - 1) {
                return true;
            }
            
            visited[nextIdx] = true;
            queue.push(nextIdx);
        }
    }
    
    return false;
}
This function uses breadth-first search to find the last index that can be reached. It starts from index 0 and adds all reachable indices to the queue. It then processes each index in the queue. For each index, it tries to reach all the reachable indices. If it finds any of the reachable indices that is the last index, it returns true. Otherwise, it adds the reachable indices to the queue and continues the process. If it can't find any reachable indices that is the last index, it returns false.