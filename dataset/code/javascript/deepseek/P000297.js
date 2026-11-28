function romanToInt(s) {
    let map = new Map();
    map.set('I', 1);
    map.set('V', 5);
    map.set('X', 10);
    map.set('L', 50);
    map.set('C', 100);
    map.set('D', 500);
    map.set('M', 1000);
    
    let num = 0, prev = 0;
    for(let i = s.length - 1; i >= 0; i--) {
        let current = map.get(s[i]);
        if (current >= prev) {
            num += current;
        } else {
            num -= current;
        }
        prev = current;
    }
    return num;
}
This function uses a map to associate each Roman numeral with its corresponding integer value. The function then iterates through the Roman numeral string in reverse order (from right to left). For each character, it adds the integer value of the current character to a running total (num), and subtracts the integer value of the previous character if the current character is less than the previous character. Finally, it returns the total.