import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        pivot = vals[-1]
        less = [x for x in vals[:-1] if x < pivot]
        greater = [x for x in vals[:-1] if x >= pivot]
        print(*(less + [pivot] + greater))
if __name__ == '__main__':
    main()