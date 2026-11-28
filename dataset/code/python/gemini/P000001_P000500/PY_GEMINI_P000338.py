import sys

def array_strings_are_equal(word1, word2) -> bool:
    return "".join(word1) == "".join(word2)

def main():
    lines = sys.stdin.read().strip().split('\n')
    if len(lines) >= 2:
        w1 = lines[0].split()
        w2 = lines[1].split()
        print("Yes" if array_strings_are_equal(w1, w2) else "No")

if __name__ == '__main__':
    main()