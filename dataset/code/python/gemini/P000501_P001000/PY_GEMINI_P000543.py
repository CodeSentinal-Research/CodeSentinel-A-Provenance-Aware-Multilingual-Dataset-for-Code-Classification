import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        nums = set()
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "addNum":
                nums.add(int(tokens[idx+1]))
                idx += 2
            elif cmd == "getIntervals":
                sorted_nums = sorted(nums)
                intervals = []
                for x in sorted_nums:
                    if intervals and intervals[-1][1] + 1 == x:
                        intervals[-1][1] = x
                    else:
                        intervals.append([x, x])
                print(" ".join(f"[{a},{b}]" for a, b in intervals))
                idx += 1
if __name__ == '__main__':
    main()