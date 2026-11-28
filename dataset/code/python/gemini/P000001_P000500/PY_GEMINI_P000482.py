import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums1 = list(map(int, tokens[1:1+n]))
        m = int(tokens[1+n])
        nums2 = list(map(int, tokens[2+n:2+n+m]))
        # Monotonic stack to track visible elements
        stack = []
        nxt = {}
        for num in nums2:
            # Pop smaller elements that are blocked from view
            while stack and stack[-1] < num:
                nxt[stack.pop()] = num
            stack.append(num)
        while stack:
            nxt[stack.pop()] = -1
        res = [nxt.get(x, -1) for x in nums1]
        print(*res)
if __name__ == '__main__':
    main()