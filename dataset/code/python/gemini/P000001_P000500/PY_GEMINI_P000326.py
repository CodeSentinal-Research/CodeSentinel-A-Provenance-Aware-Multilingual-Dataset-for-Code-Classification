import sys

def count_segments(s: str) -> int:
    return len(s.split())

def main():
    content = sys.stdin.read()
    print(count_segments(content))

if __name__ == '__main__':
    main()