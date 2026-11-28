// P001421 - Minimum Index Sum of Two Lists
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums1 = [], nums2 = [];
    let ptr = 1;
    for (let i = 0; i < n; i++) nums1.push(parseInt(input[ptr++], 10));
    for (let i = 0; i < n; i++) nums2.push(parseInt(input[ptr++], 10));
    let dp1 = 1, dp2 = 1, maxLen = 1;
    for (let i = 1; i < n; i++) {
        let nextDp1 = 1, nextDp2 = 1;
        if (nums1[i] >= nums1[i - 1]) nextDp1 = Math.max(nextDp1, dp1 + 1);
        if (nums1[i] >= nums2[i - 1]) nextDp1 = Math.max(nextDp1, dp2 + 1);
        if (nums2[i] >= nums1[i - 1]) nextDp2 = Math.max(nextDp2, dp1 + 1);
        if (nums2[i] >= nums2[i - 1]) nextDp2 = Math.max(nextDp2, dp2 + 1);
        dp1 = nextDp1;
        dp2 = nextDp2;
        maxLen = Math.max(maxLen, dp1, dp2);
    }
    console.log(maxLen);
}

main();
