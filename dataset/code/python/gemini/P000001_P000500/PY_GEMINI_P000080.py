import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        c = lines[0][0]
        print('Alphabet' if c.isalpha() else 'Not Alphabet')
if __name__ == '__main__':
    main()