Here is the JavaScript code for the Hot Potato game:

function hotPotato(N, K) {
    var queue = [];
    for (var i = 1; i <= N; i++) {
        queue.push(i);
    }

    while (queue.length > 1) {
        for (var i = 0; i < K; i++) {
            queue.push(queue.shift());
        }
        queue.shift();
    }

    return queue[0];
}
This code creates a queue for the players. It then enters a loop which repeats K times for each player. In each iteration, the current player is moved to the end of the queue. This simulates the passing of the token to the next player in the queue, and the player who moves to the end of the queue is removed from the queue. The function finally returns the number of the winning player.