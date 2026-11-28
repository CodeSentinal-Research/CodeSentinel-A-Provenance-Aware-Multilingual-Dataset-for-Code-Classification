Here is a simple implementation of the Minimum Genetic Mutation problem using JavaScript. This code assumes that you have a function getNeighbors() that generates all possible neighbors for a given gene.

function minMutation(start, end, bank, n) {
    if (!bank.includes(end)) {
        return -1;
    }
    
    let queue = [start];
    let visited = new Set([start]);
    let mutations = 0;
    
    while (queue.length) {
        let size = queue.length;
        for (let i = 0; i < size; i++) {
            let curr = queue.shift();
            if (curr === end) {
                return mutations;
            }
            let neighbors = getNeighbors(curr);
            for (let neighbor of neighbors) {
                if (!visited.has(neighbor) && bank.includes(neighbor)) {
                    visited.add(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        mutations++;
    }
    
    return -1;
}

function getNeighbors(gene) {
    let neighbors = [];
    for (let i = 0; i < gene.length; i++) {
        let arr = gene.split('');
        if (arr[i] === 'A') arr[i] = 'B';
        if (arr[i] === 'C') arr[i] = 'D';
        if (arr[i] === 'G') arr[i] = 'I';
        if (arr[i] === 'T') arr[i] = 'V';
        neighbors.push(arr.join(''));
        arr[i] = gene[i];
    }
    return neighbors;
}

In this code, we use a breadth-first search algorithm to find the minimum number of mutations. We start from the start gene and move towards the end gene using a queue. For each gene, we generate its neighbors and add them to the queue if they are in the bank and not visited before. We keep track of the number of mutations and return -1 if the target gene is not found in the bank.

Please note that this is a simple implementation and may not work for all cases. The getNeighbors function generates all possible neighbors for a given gene. You need to implement this function according to your specific requirements. Also, this code assumes that all genes in the bank are valid and the gene bank is a valid input.