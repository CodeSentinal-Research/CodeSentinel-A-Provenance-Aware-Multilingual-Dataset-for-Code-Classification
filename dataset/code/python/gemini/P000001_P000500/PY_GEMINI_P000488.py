import sys
def largest_rectangle_area(heights):
    heights = heights + [0]
    stack = [-1]
    max_area = 0
    for i in range(len(heights)):
        # Maintain monotonic stack property by popping smaller elements
        while stack and stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
            h = heights[stack.pop()]
            w = i - stack[-1] - 1
            max_area = max(max_area, h * w)
        stack.append(i)
    return max_area

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        r = int(tokens[0])
        c = int(tokens[1])
        idx = 2
        heights = [0] * c
        max_area = 0
        for _ in range(r):
            row = [int(tokens[idx + j]) for j in range(c)]
            idx += c
            for j in range(c):
                heights[j] = heights[j] + 1 if row[j] == 1 else 0
            max_area = max(max_area, largest_rectangle_area(heights))
        print(max_area)
if __name__ == '__main__':
    main()