import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    nums1 = list(map(int, input_data[idx:idx+n])); idx += n
    nums2 = list(map(int, input_data[idx:idx+m]))
    
    merged = []
    i, j = 0, 0
    while i < n and j < m:
        if nums1[i] <= nums2[j]:
            merged.append(nums1[i])
            i += 1
        else:
            merged.append(nums2[j])
            j += 1
            
    merged.extend(nums1[i:])
    merged.extend(nums2[j:])
    
    print(*merged)

solve()

