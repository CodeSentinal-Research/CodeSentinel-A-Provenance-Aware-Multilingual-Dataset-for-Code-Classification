import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        age = int(lines[0])
        print('Eligible' if age >= 18 else 'Not Eligible')
if __name__ == '__main__':
    main()