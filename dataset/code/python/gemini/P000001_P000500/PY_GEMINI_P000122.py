import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        n = int(lines[0])
        arr = [int(x) for x in lines[1:n+1]]
        max_so_far = arr[0]
        curr_max = arr[0]
        for x in arr[1:]:
            curr_max = max(x, curr_max + x)
            max_so_far = max(max_so_far, curr_max)
        print(max_so_far)
if __name__ == '__main__':
    main()