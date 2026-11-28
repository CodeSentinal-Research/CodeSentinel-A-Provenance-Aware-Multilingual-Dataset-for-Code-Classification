import sys

def can_be_typed_words(text: str, broken_letters: str) -> int:
    broken = set(broken_letters)
    count = 0
    for w in text.split():
        if not (set(w) & broken):
            count += 1
    return count

def main():
    lines = sys.stdin.read().strip().split('\n')
    if len(lines) >= 2:
        print(can_be_typed_words(lines[0].strip(), lines[1].strip()))
    elif len(lines) == 1:
        parts = lines[0].split()
        if len(parts) >= 2:
            print(can_be_typed_words(" ".join(parts[:-1]), parts[-1]))

if __name__ == '__main__':
    main()