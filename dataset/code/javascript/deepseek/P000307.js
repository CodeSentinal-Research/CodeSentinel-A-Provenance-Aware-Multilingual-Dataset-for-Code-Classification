Sure, here is a JavaScript solution that uses a Depth-First Search (DFS) algorithm to find all possible valid strings from a given string:

function removeInvalidParentheses(s) {
    let valid = new Set();
    let visited = new Set();
    visited.add(s);
    let queue = [s];

    while (queue.length) {
        let len = queue.length;
        for (let i = 0; i < len; i++) {
            let t = queue.shift();
            if (isValid(t)) {
                valid.add(t);
            } else {
                for (let j = 0; j < t.length; j++) {
                    if (t[j] == '(' || t[j] == ')') {
                        let pair = t.slice(0, j) + t.slice(j + 1, t.length);
                        if (!visited.has(pair)) {
                            visited.add(pair);
                            queue.push(pair);
                        }
                    }
                }
            }
        }
    }

    return Array.from(valid).sort();
}

function isValid(s) {
    let count = 0;
    for (let c of s) {
        if (c == '(') count += 1;
        else if (c == ')') {
            if (count == 0) return false;
            count -= 1;
        }
    }
    return count == 0;
}
This code uses a Breadth-First Search (BFS) approach. It starts from the input string and explores all possible strings by changing a character at a time. It uses a `Set` to store the valid strings and a `Set` to store the visited strings. In the end, it returns all the valid strings as an array.