# problem title : Decode String at Index
# Solve the stated task using standard input and standard output.
import sys
def decode_at_index(s, k):
    size = 0
    for c in s:
        if c.isdigit(): size *= int(c)
        else: size += 1
    for c in reversed(s):
        k %= size
        if k == 0 and c.isalpha(): return c
        if c.isdigit(): size //= int(c)
        else: size -= 1
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        k = int(tokens[1])
        print(decode_at_index(s, k))
if __name__ == '__main__':
    main()
