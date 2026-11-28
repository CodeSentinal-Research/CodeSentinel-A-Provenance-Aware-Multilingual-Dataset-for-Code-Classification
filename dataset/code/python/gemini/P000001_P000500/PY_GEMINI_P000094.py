import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = lines[0]
        n = int(s)
        d_sum = sum(int(c) for c in s if c.isdigit())
        print('Harshad' if d_sum > 0 and n % d_sum == 0 else 'Not Harshad')
if __name__ == '__main__':
    main()