function countTriplets(nums, target) {
    nums = [...nums].sort((a,b) => a-b);
    const n = nums.length;
    let count = 0;
    for (let i = 0; i < n-2; i++) {
        let l = i+1, r = n-1;
        while (l < r) {
            const s = nums[i]+nums[l]+nums[r];
            if (s === target) {
                if (nums[l] === nums[r]) { const m=r-l+1; count+=m*(m-1)/2; break; }
                let lc=1, rc=1;
                while (l+lc<r && nums[l+lc]===nums[l]) lc++;
                while (r-rc>l && nums[r-rc]===nums[r]) rc++;
                count+=lc*rc; l+=lc; r-=rc;
            } else if (s < target) l++;
            else r--;
        }
    }
    return count;
}
module.exports = { countTriplets };
