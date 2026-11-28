Here is the JavaScript solution for the problem:

/** 
 * Forward declaration of isBadVersion API, 
 * @param {number} version 
 * @return {boolean} 
 * 
 */
function isBadVersion(version) {};

/**
 * @param {number} n 
 * @return {number}
 */
function firstBadVersion(n) {
    let start = 1, end = n;
    while(start < end){
        let mid = Math.floor(start + (end - start) / 2);
        if(isBadVersion(mid) === true){
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return end;
}

The code uses binary search to find the first bad version. It works by repeatedly dividing the search space in half until it finds a bad version. When a bad version is found, the start index is moved to mid + 1 and the process is repeated. When the function returns, the end index is the first bad version.

This function assumes that `isBadVersion(version)` is a correct API that returns true if the version is bad and false otherwise. The API is defined in the problem statement.

This code is valid for the given constraints. For example, if `isBadVersion(mid)` always returns false, then the loop will run indefinitely. If `isBadVersion(mid)` always returns true, then the loop will return the first mid as the first bad version.