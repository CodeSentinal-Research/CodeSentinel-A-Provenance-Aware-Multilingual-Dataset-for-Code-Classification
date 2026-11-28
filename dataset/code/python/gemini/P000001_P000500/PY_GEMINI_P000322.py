import sys

def detect_capital_use(word: str) -> bool:
    return word.isupper() or word.islower() or word.istitle()

def main():
    lines = sys.stdin.read().split()
    if lines:
        print("Yes" if detect_capital_use(lines[0]) else "No")

if __name__ == '__main__':
    main()