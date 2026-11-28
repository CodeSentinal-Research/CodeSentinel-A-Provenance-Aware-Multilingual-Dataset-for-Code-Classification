n = int(input())
nums1 = list(map(int, input().split()))
m = int(input())
nums2 = list(map(int, input().split()))
nge = {}
stack = []
for x in nums2:
    while stack and stack[-1] < x:
        nge[stack.pop()] = x
    stack.append(x)
res = [nge.get(x, -1) for x in nums1]
print(" ".join(map(str, res)))
