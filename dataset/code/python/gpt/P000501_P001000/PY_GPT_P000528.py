# problem title : Count Collisions on a Road
# Solve the stated task using standard input and standard output.
import sys
def main():
    s = sys.stdin.read().strip()
    if s:
        s = s.lstrip('L').rstrip('R')
        print(len(s) - s.count('S'))
if __name__ == '__main__':
    main()
