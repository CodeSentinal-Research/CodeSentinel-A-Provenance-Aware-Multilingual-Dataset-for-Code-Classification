import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        ch = lines[0][0].lower()
        print('Vowel' if ch in 'aeiou' else 'Consonant')
if __name__ == '__main__':
    main()