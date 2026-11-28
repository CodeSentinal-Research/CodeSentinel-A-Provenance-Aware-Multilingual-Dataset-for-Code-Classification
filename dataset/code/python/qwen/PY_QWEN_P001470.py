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
    
    # Merge into nums1 and nums2 such that nums1 has smallest n elements
    # Using gap algorithm or simple swap approach for O(N+M) space constraint logic
    # Here we use a simple sort of combined array then split, but problem says "without extra space" usually implies O(1) auxiliary.
    # Standard O(1) space merge:
    
    i = n - 1
    j = 0
    while i >= 0 and j < m:
        if nums1[i] > nums2[j]:
            nums1[i], nums2[j] = nums2[j], nums1[i]
            i -= 1
            j += 1
        else:
            break
            
    nums1.sort()
    nums2.sort()
    
    print(*nums1)
    print(*nums2)

solve()

