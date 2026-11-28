function removeInvalidParentheses(str) {
    let queue = new Set(['']);
    let visited = new Set();
    visited.add(str);

    while(queue.size) {
        let size = queue.size;
        for(let i=0; i<size; i++) {
            let temp = queue.values().next().value;
            queue.delete(temp);
            if(temp.length == 0) return visited;
            for(let j=0; j<temp.length; j++) {
                if(temp[j] == '(' || temp[j] == ')') {
                    let str1 = temp.slice(0, j) + temp.slice(j+1, temp.length);
                    if(!visited.has(str1)) {
                        queue.add(str1);
                        visited.add(str1);
                    }
                }
            }
        }
    }
}

console.log(removeInvalidParentheses('()()()()()()()').sort());