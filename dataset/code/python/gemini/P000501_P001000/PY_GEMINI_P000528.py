import sys
def main():
    s = sys.stdin.read().strip()
    if s:
        s = s.lstrip('L').rstrip('R')
        print(len(s) - s.count('S'))
if __name__ == '__main__':
    main()