import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        s1, s2 = lines[0], lines[1]
        print('Anagram' if sorted(s1) == sorted(s2) else 'Not Anagram')
if __name__ == '__main__':
    main()