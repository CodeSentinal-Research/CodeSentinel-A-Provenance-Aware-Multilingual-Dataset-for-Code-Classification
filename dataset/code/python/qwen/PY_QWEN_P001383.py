import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    m = int(input_data[1])
    nums1 = list(map(int, input_data[2:2+n]))
    nums2 = list(map(int, input_data[2+n:2+n+m]))
    
    counter1 = Counter(nums1)
    counter2 = Counter(nums2)
    
    result = []
    for num in counter1:
        if num in counter2:
            count = min(counter1[num], counter2[num])
            result.extend([num] * count)
            
    result.sort()
    print(" ".join(map(str, result)))

solve()

