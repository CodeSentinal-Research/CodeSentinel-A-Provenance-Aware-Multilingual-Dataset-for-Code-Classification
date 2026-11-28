Here is a JavaScript code using recursive approach to solve the problem. This code finds all the possible combinations of removing a parenthesis from the given string and stores them in a set to remove duplicates. It uses a depth first search to visit all possible combinations.

function removeInvalidParentheses(s) {
    let set = new Set(), visited = new Set(), queue = new Set([s]);
    set.add(s);
    while(queue.size > 0) {
        let current = queue.values().next().value;
        queue.clear();
        if(set.has(current)) continue;
        set.add(current);
        if(isValid(current)) {
            console.log(current);
        } else {
            let len = current.length;
            for(let i = 0; i < len; i++) {
                if(current[i] == '(' || current[i] == ')') {
                    let next = current.slice(0, i) + current.slice(i+1, len);
                    if(!visited.has(next)) {
                        visited.add(next);
                        queue.add(next);
                    }
                }
            }
        }
    }
}

function isValid(s) {
    let count = 0;
    for(let c of s) {
        if(c == '(') count++;
        else if(c == ')') {
            if(count == 0) return false;
            count--;
        }
    }
    return count == 0;
}

In this code, the removeInvalidParentheses function starts with an initial string and then continuously removes a parenthesis from the string until there is no more valid strings left. The isValid function checks if a string is a valid parentheses string.

You can call the function with a string as input:

removeInvalidParentheses('()()()()()');

This will print all the possible valid strings in lexicographical order.

Note: This solution has a time complexity of O(n*2^n) as for each string, we generate two new strings (one that is valid and one that is not), we traverse all of them and add them to the queue and set.