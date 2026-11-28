function topKFrequent(nums, k) {
    let counts = {};
    for(let num of nums) {
        if(counts[num] == null) {
            counts[num] = 0;
        }
        counts[num]++;
    }

    let bucket = Array(nums.length).fill(0).map(() => []);
    for(let num in counts) {
        bucket[counts[num]].push(parseInt(num));
    }

    let res = [];
    for(let i = bucket.length - 1; i >= 0 && res.length < k; i--) {
        for(let num of bucket[i]) {
            res.push(num);
        }
    }

    return res;
}