# problem title : Generate All Valid Abbreviations of a Word
# Solve the stated task using standard input and standard output.
import sys
def get_abbrevs(word):
    res = []
    def backtrack(idx, cur, count):
        if idx == len(word):
            res.append(cur + (str(count) if count > 0 else ""))
            return
        # Abbreviate current char
        backtrack(idx + 1, cur, count + 1)
        # Keep current char
        backtrack(idx + 1, cur + (str(count) if count > 0 else "") + word[idx], 0)
    backtrack(0, "", 0)
    return sorted(res)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        for abbr in get_abbrevs(tokens[0]):
            print(abbr)
if __name__ == '__main__':
    main()
