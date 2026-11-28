import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        # Serialized input filtered for nulls
        res = [x for x in tokens if x not in ("null", "#", "N")]
        print(*res)
if __name__ == '__main__':
    main()