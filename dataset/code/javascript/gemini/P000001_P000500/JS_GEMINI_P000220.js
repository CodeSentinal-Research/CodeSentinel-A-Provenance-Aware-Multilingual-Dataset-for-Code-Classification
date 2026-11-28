function findCelebrity(n, knows) {
    let cand = 0;
    for (let i = 1; i < n; i++) {
        if (knows(cand, i)) cand = i;
    }

    for (let i = 0; i < n; i++) {
        if (i !== cand) {
            if (knows(cand, i) || !knows(i, cand)) return -1;
        }
    }
    return cand;
}

module.exports = { findCelebrity };