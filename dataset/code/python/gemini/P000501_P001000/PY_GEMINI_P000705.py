import sys
def gen_subseq(arr, idx, cur):
    if idx == len(arr):
        print(*cur)
        return
    gen_subseq(arr, idx + 1, cur)
    gen_subseq(arr, idx + 1, cur + [arr[idx]])
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        gen_subseq(nums, 0, [])
if __name__ == '__main__':
    main()