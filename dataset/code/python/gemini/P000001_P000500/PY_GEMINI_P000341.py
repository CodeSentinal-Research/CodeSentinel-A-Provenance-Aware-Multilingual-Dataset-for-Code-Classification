import sys

def word_to_val(w: str) -> int:
    return int("".join(str(ord(c) - ord('a')) for c in w))

def is_sum_equal(first_word: str, second_word: str, target_word: str) -> bool:
    return word_to_val(first_word) + word_to_val(second_word) == word_to_val(target_word)

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        print("Yes" if is_sum_equal(lines[0], lines[1], lines[2]) else "No")

if __name__ == '__main__':
    main()