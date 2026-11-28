import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        # Standard length of cycle: if pos is given or list contains cycle
        # If -1 / 0 => 0 else pos to end length
        print(int(tokens[0]) if len(tokens) == 1 and tokens[0] != "-1" else 0)
if __name__ == '__main__':
    main()