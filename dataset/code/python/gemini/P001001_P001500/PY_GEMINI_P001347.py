from typing import Dict, List

def solve_cryptarithmetic(s1: str, s2: str, s3: str) -> bool:
    """Solves 'Cryptarithmetic Puzzle' by applying optimal Backtracking logic."""
    unique_chars = list(set(s1 + s2 + s3))
    if len(unique_chars) > 10:
        return False

    used = [False] * 10
    char_map = {}

    def is_valid():
        if char_map[s1[0]] == 0 or char_map[s2[0]] == 0 or char_map[s3[0]] == 0:
            return False
        v1 = int("".join(str(char_map[c]) for c in s1))
        v2 = int("".join(str(char_map[c]) for c in s2))
        v3 = int("".join(str(char_map[c]) for c in s3))
        return v1 + v2 == v3

    def backtrack(idx: int) -> bool:
        if idx == len(unique_chars):
            return is_valid()

        c = unique_chars[idx]
        for digit in range(10):
            if not used[digit]:
                used[digit] = True
                char_map[c] = digit
                if backtrack(idx + 1):
                    return True
                used[digit] = False
                del char_map[c]
        return False

    return backtrack(0)

if __name__ == '__main__':
    s1, s2, s3 = input().split()
    print("YES" if solve_cryptarithmetic(s1, s2, s3) else "NO")