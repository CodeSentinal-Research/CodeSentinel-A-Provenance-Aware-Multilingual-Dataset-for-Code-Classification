import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        n = int(lines[0])
        arr = [int(x) for x in lines[1:n+1]]
        max_cnt = 0
        curr_cnt = 0
        for x in arr:
            if x == 1:
                curr_cnt += 1
                max_cnt = max(max_cnt, curr_cnt)
            else:
                curr_cnt = 0
        print(max_cnt)
if __name__ == '__main__':
    main()