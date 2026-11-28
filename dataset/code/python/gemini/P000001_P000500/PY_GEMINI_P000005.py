import sys


def solve():
    """Solves 'Find Remainder' by applying optimal Basic logic."""
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    out = []

    # Check if input follows the standard (T, test cases...) format
    try:
        t = int(input_data[0])
        if len(input_data) == 2 * t + 1:
            idx = 1
            for _ in range(t):
                a = int(input_data[idx])
                b = int(input_data[idx + 1])
                out.append(str(a % b))
                idx += 2
            print("\n".join(out))
            return
    except (ValueError, IndexError):
        pass

    # Fallback for streams of pairs without a leading count T
    idx = 0
    while idx + 1 < len(input_data):
        a = int(input_data[idx])
        b = int(input_data[idx + 1])
        out.append(str(a % b))
        idx += 2

    if out:
        print("\n".join(out))


if __name__ == "__main__":
    solve()