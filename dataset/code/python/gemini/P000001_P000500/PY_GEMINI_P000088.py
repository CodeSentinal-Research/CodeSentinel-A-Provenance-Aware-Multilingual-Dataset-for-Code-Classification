import sys, math
def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        if n < 0:
            print('Not Perfect Square')
            return
        sq = int(math.isqrt(n))
        print('Perfect Square' if sq * sq == n else 'Not Perfect Square')
if __name__ == '__main__':
    main()