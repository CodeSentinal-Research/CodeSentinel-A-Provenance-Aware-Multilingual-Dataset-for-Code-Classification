function strStr(haystack, needle) {
    if(needle.length == 0) return 0;
    if(haystack.length == 0) return -1;
    if(haystack.length > needle.length) return -1;

    let n = haystack.length;
    let m = needle.length;

    for (let i = 0; i <= n - m; i++) {
        let j;
        for (j = 0; j < m; j++) {
            if (haystack[i + j] !== needle[j])
                break;
        }
        if (j == m) return i;
    }

    return -1;
}