import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    m = int(input_data[1])
    nums1 = list(map(int, input_data[2:2+n]))
    nums2 = list(map(int, input_data[2+n:2+n+m]))
    
    set1 = set(nums1)
    set2 = set(nums2)
    
    only_in_1 = sorted(set1 - set2)
    only_in_2 = sorted(set2 - set1)
    
    print(" ".join(map(str, only_in_1)))
    print(" ".join(map(str, only_in_2)))

solve()

