Here's the JavaScript code to solve the problem:

function makesquare(matchsticks) {
    const totalLength = matchsticks.reduce((a, b) => a + b, 0);
    if (matchsticks.length < 4 || totalLength % 4 !== 0) return false;
    
    matchsticks.sort((a, b) => b - a);
    const edgeLength = totalLength / 4;
    
    const edges = [0, 0, 0, 0];
    const visit = (index) => {
        if (edges[index] + matchsticks[index] > edgeLength) return false;
        if (edges[index] + matchsticks[index] === edgeLength) {
            if (index === 0) return true;
            return visit(index - 1);
        } else {
            for (let i = 0; i < index; i++) {
                if (visit(i)) return true;
                edges[index] += matchsticks[index];
            }
            return false;
        }
    };
    
    for (let i = 0; i < matchsticks.length; i++) {
        if (!visit(i)) return false;
        edges[0] = edges[1] = edges[2] = edges[3] = 0;
    }
    
    return true;
}

This code uses the Depth First Search (DFS) algorithm to try all possible combinations of matchsticks to form a square. The `visit` function is called recursively for each matchstick, and if it returns true, it means a solution exists. The `matchsticks` array is sorted in descending order to simplify the process of finding a possible solution. The time complexity is O(n^n) due to the use of DFS.