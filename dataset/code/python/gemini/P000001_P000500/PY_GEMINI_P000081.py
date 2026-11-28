import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        print('Digit' if lines[0][0].isdigit() else 'Not Digit')
if __name__ == '__main__':
    main()