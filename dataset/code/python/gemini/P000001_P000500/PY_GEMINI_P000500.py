import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        ops = tokens[1:1+n]
        depth = 0
        for op in ops:
            if op == "../":
                if depth > 0: depth -= 1
            elif op == "./":
                pass
            else:
                depth += 1
        print(depth)
if __name__ == '__main__':
    main()