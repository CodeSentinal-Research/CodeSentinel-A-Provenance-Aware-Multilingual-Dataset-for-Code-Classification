import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        n_str = lines[0]
        n = int(n_str)
        p = len(n_str)
        arm = sum(int(d) ** p for d in n_str)
        print('Armstrong' if arm == n else 'Not Armstrong')
if __name__ == '__main__':
    main()