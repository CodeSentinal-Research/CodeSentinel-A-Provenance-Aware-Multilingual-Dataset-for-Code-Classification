import sys

def valid_word_abbreviation(word: str, abbr: str) -> bool:
    i = j = 0
    while i < len(word) and j < len(abbr):
        if abbr[j].isdigit():
            if abbr[j] == '0':
                return False
            num = 0
            while j < len(abbr) and abbr[j].isdigit():
                num = num * 10 + int(abbr[j])
                j += 1
            i += num
        else:
            if word[i] != abbr[j]:
                return False
            i += 1
            j += 1
    return i == len(word) and j == len(abbr)

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print("Yes" if valid_word_abbreviation(lines[0], lines[1]) else "No")

if __name__ == '__main__':
    main()