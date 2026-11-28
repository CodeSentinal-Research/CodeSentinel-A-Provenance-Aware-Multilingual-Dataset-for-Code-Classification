import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        emails = tokens[1:n+1]
        domain = tokens[n+1]
        if not domain.startswith('@'): domain = '@' + domain
        for e in emails:
            if e.endswith(domain):
                print(e)
if __name__ == '__main__':
    main()