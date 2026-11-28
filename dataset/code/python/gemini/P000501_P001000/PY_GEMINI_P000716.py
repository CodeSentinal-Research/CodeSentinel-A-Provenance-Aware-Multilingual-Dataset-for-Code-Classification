import sys
mapping = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
def letter_comb(digits, idx, cur):
    if idx == len(digits):
        print(cur)
        return
    for c in mapping[digits[idx]]:
        letter_comb(digits, idx + 1, cur + c)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        digits = tokens[0]
        letter_comb(digits, 0, "")
if __name__ == '__main__':
    main()