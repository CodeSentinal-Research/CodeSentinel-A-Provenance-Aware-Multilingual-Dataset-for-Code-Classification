function findCeiling(N, target, arr) {
    let start = 0;
    let end = arr.length - 1;
    
    while (start <= end) {
        let mid = Math.floor((start + end) / 2);
        
        if (arr[mid] == target) {
            return arr[mid];
        }
        
        if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return -1;
}