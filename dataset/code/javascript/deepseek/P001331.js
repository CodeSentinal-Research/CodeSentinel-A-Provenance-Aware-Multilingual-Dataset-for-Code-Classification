function restoreIpAddresses(s) {
    const restore = (index, split, ip, res) => {
        // base case
        if (split == 4) {
            if (index === s.length) {
                res.push(ip.join('.'));
            }
            return;
        }
        // if the string length is greater than 12 or the current index is greater than the string length
        // then return as we cannot form a valid ip with the remaining characters
        if (index >= s.length || split * 3 > s.length)
            return;
        
        // for each possible remaining segment length
        for (let len = 1; len < 4 && index + len <= s.length; len++) {
            const segment = s.slice(index, index + len);
            // skip if the segment is 0 and the segment length > 1
            if (segment[0] === '0' && len > 1)
                break;
            
            if (len > 1 && segment + s.slice(index + len) > s)
                break;
            
            ip[split] = segment;
            restore(index + len, split + 1, ip, res);
        }
    }
    
    const res = [];
    restore(0, 0, [], res);
    return res;
}