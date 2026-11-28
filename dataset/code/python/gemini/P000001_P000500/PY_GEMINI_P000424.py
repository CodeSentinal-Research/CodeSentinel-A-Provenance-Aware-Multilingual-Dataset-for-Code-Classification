import sys
from collections import Counter
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        emails = tokens[1:n+1]
        cnt = Counter(emails)
        seen = set()
        for e in emails:
            if cnt[e] > 1 and e not in seen:
                print(e)
                seen.add(e)
if __name__ == '__main__':
    main()