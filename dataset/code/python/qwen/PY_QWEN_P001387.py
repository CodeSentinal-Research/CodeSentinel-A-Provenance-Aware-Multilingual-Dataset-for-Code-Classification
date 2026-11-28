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
    
    if Counter(nums1) == Counter(nums2):
        print("YES")
    else:
        print("NO")

solve()

