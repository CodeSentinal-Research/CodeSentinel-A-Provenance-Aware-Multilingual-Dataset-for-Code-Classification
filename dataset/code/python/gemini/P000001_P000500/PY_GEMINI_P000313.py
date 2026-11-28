import sys
import re

def is_valid_number(s: str) -> bool:
    pattern = r'^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?$'
    return bool(re.match(pattern, s.strip()))

def main():
    line = sys.stdin.read().strip()
    if line:
        print("Valid" if is_valid_number(line) else "Invalid")

if __name__ == '__main__':
    main()