import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n1, n2, n3 = int(tokens[0]), int(tokens[1]), int(tokens[2])
        idx = 3
        a1 = list(map(int, tokens[idx:idx+n1])); idx += n1
        a2 = list(map(int, tokens[idx:idx+n2])); idx += n2
        a3 = list(map(int, tokens[idx:idx+n3])); idx += n3
        common = sorted(list(set(a1) & set(a2) & set(a3)))
        print(*(common if common else [-1]))
if __name__ == '__main__':
    main()