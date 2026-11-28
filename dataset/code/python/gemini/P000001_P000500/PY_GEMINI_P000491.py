import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        m = int(tokens[0])
        target = list(map(int, tokens[1:1+m]))
        n = int(tokens[1+m])
        target_idx = 0
        ops = []
        for i in range(1, n + 1):
            if target_idx == len(target): break
            ops.append("Push")
            if target[target_idx] == i:
                target_idx += 1
            else:
                ops.append("Pop")
        for op in ops: print(op)
if __name__ == '__main__':
    main()