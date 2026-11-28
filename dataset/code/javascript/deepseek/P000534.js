Here is the JavaScript code for the problem:

function predictPartyVictory(senate) {
    let queue = [];
    let countR = [0];
    let countD = [0];
    senate.split('').forEach((c, i) => {
        if (c === 'R') countR[0]++;
        else countD[0]++;
    });

    while (countR[0] > 0 && countD[0] > 0) {
        countR.unshift(countR.pop() - 1);
        countD.unshift(countD.pop() - 1);