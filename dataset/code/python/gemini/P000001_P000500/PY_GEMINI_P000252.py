import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = lines[0]
        print('Palindrome' if s == s[::-1] else 'Not Palindrome')
if __name__ == '__main__':
    main()