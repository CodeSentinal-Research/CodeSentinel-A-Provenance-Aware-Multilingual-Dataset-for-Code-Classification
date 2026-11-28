import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    deliciousness = list(map(int, input_data[1:1+n]))
    
    counter = Counter(deliciousness)
    max_val = max(deliciousness) if deliciousness else 0
    max_power = 1
    while max_power <= 2 * max_val:
        max_power <<= 1
        
    pairs = 0
    MOD = 10**9 + 7
    
    for num in counter:
        for power in range(1, 22): # 2^21 > 2*10^5 * 2^20 approx
            target = (1 << power) - num
            if target in counter:
                if target == num:
                    pairs += counter[num] * (counter[num] - 1) // 2
                elif target > num:
                    pairs += counter[num] * counter[target]
                    
    print(pairs % MOD)

solve()

