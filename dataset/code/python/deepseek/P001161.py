def is_match(text, pattern):
    if not pattern:
        return not text

    first = pattern[0]
    second = pattern[1:3]

    if len(second) > 2:
        return False

    if first == '*':
        return is_match(text, pattern[2:]) or first in text and is_match(text[1:], pattern)
    elif first == '?' or first in text:
        return is_match(text[1:], pattern[1:])

    return False

def main():
    text = input().strip()
    pattern = input().strip()

    print('YES' if is_match(text, pattern) else 'NO')

if __name__ == "__main__":
    main()