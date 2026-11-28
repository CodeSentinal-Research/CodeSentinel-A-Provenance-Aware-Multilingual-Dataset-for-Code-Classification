function countSubarrays(nums) {
    let count = 0;
    let positive = 0;
    let negative = 0;

    for (let num of nums) {
        if (num > 0) {
            positive++;
        } else if (num < 0) {
            negative++;
        }
        if (positive === negative && positive > 0) {
            count += positive;
        }
    }

    return count;
}