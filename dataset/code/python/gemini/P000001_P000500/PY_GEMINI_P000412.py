import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        contacts = tokens[1:n+1]
        target = tokens[n+1].lower()
        for c in contacts:
            if c.lower() == target:
                print(c)
if __name__ == '__main__':
    main()