import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        c = lines[0][0]
        print('Uppercase' if c.isupper() else 'Lowercase')
if __name__ == '__main__':
    main()