import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:n+1]))
        q = int(tokens[n+1])
        queries = list(map(int, tokens[n+2:n+2+q]))
        for query in queries:
            found = False
            for val in arr:
                if val == query:
                    found = True
                    break
            print("Found" if found else "Not Found")

if __name__ == '__main__':
    main()