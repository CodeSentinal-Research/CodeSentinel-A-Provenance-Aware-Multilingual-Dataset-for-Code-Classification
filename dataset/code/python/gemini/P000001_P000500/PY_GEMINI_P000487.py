import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        height = list(map(int, tokens[1:1+n]))
        l, r = 0, n - 1
        l_max, r_max = 0, 0
        water = 0
        while l < r:
            if height[l] < height[r]:
                if height[l] >= l_max: l_max = height[l]
                else: water += l_max - height[l]
                l += 1
            else:
                if height[r] >= r_max: r_max = height[r]
                else: water += r_max - height[r]
                r -= 1
        print(water)
if __name__ == '__main__':
    main()