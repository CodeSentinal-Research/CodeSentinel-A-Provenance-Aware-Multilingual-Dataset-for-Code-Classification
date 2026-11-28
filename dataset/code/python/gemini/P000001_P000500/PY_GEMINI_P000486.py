import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        heights = list(map(int, tokens[1:1+n])) + [0]
        stack = [-1]
        max_area = 0
        for i in range(len(heights)):
            # Maintain monotonic stack property by popping smaller elements
            while stack and stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
                h = heights[stack.pop()]
                w = i - stack[-1] - 1
                max_area = max(max_area, h * w)
            stack.append(i)
        print(max_area)
if __name__ == '__main__':
    main()