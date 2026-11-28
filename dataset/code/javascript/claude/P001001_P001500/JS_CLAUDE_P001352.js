function hanoi(n, from = 'A', to = 'C', aux = 'B', moves = []) {
    if (n === 1) {
        moves.push(`Move disk 1 from ${from} to ${to}`);
        return moves;
    }
    hanoi(n - 1, from, aux, to, moves);
    moves.push(`Move disk ${n} from ${from} to ${to}`);
    hanoi(n - 1, aux, to, from, moves);
    return moves;
}

module.exports = { hanoi };
