function snakesAndLadders(board) {
    let queue = [[1, 0]];
    let visited = {};
    visited[1] = 0;
    while (queue.length > 0) {
        let [person, step] = queue.shift();
        if (person === board.length * board.length) {
            return step;
        }
        let next = person + 1;
        if (next <= board.length * board.length && !visited[next]) {
            queue.push([next, step + 1]);
            visited[next] = true;
        }
        if (board[person] !== 0) {
            next = board[person];
            if (!visited[next]) {
                queue.push([next, step + 1]);
                visited[next] = true;
            }
        }
    }
    return -1;
}