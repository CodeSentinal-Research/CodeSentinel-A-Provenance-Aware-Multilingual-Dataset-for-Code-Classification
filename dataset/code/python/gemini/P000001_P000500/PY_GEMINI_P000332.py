import sys

def custom_sort_string(order: str, s: str) -> str:
    """Sorts the input array into ordered sequence."""
    rank = {c: i for i, c in enumerate(order)}
    return "".join(sorted(s, key=lambda c: rank.get(c, 1000)))

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print(custom_sort_string(lines[0], lines[1]))

if __name__ == '__main__':
    main()