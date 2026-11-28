// P001450 - Rank Teams by Votes
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const v = parseInt(input[0], 10);
    const votes = [];
    for (let i = 0; i < v; i++) votes.push(input[1 + i]);
    const numTeams = votes[0].length;
    const count = new Map();
    for (const c of votes[0]) {
        count.set(c, new Array(numTeams).fill(0));
    }
    for (const vote of votes) {
        for (let i = 0; i < vote.length; i++) {
            count.get(vote[i])[i]++;
        }
    }
    const teams = Array.from(count.keys());
    teams.sort((a, b) => {
        const countA = count.get(a);
        const countB = count.get(b);
        for (let i = 0; i < numTeams; i++) {
            if (countA[i] !== countB[i]) {
                return countB[i] - countA[i];
            }
        }
        return a.localeCompare(b);
    });
    console.log(teams.join(""));
}

main();
