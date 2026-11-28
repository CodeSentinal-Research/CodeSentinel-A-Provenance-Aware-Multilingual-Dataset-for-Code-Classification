function majorityElementNBy3(nums) {
    let c1, c2, cnt1 = 0, cnt2 = 0;
    for (const x of nums) {
        if (x === c1) cnt1++;
        else if (x === c2) cnt2++;
        else if (cnt1 === 0) { c1 = x; cnt1 = 1; }
        else if (cnt2 === 0) { c2 = x; cnt2 = 1; }
        else { cnt1--; cnt2--; }
    }
    const threshold = Math.floor(nums.length / 3);
    const res = [];
    for (const c of [c1, c2]) {
        if (c !== undefined && nums.filter(x => x === c).length > threshold) res.push(c);
    }
    return res;
}
module.exports = { majorityElementNBy3 };
