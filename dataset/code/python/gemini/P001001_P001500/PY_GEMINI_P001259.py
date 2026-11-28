def min_swaps_bracket_balance(s: str) -> int:
    unbalanced = 0
    swaps = 0
    for c in s:
        if c == '[':
            if unbalanced > 0:
                unbalanced -= 1
        else:
            unbalanced += 1
    return (unbalanced + 1) // 2

if __name__ == '__main__':
    s = input().strip()
    print(min_swaps_bracket_balance(s))