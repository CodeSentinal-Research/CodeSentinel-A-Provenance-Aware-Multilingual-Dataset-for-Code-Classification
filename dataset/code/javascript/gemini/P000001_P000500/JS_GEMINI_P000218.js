function majorityElement(nums) {
    let c1 = null, c2 = null;
    let cnt1 = 0, cnt2 = 0;

    for (const x of nums) {
        if (x === c1) cnt1++;
        else if (x === c2) cnt2++;
        else if (cnt1 === 0) { c1 = x; cnt1 = 1; }
        else if (cnt2 === 0) { c2 = x; cnt2 = 1; }
        else { cnt1--; cnt2--; }
    }

    cnt1 = 0; cnt2 = 0;
    for (const x of nums) {
        if (x === c1) cnt1++;
        else if (x === c2) cnt2++;
    }

    const res = [];
    const n = nums.length;
    if (cnt1 > Math.floor(n / 3)) res.push(c1);
    if (c2 !== null && c2 !== c1 && cnt2 > Math.floor(n / 3)) res.push(c2);
    return res;
}

module.exports = { majorityElement };