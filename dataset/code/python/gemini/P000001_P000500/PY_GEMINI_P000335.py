import sys

def camel_match(queries, pattern: str):
    res = []
    for q in queries:
        i = 0
        matched = True
        for c in q:
            if i < len(pattern) and c == pattern[i]:
                i += 1
            elif c.isupper():
                matched = False
                break
        res.append(matched and i == len(pattern))
    return res

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        pattern = tokens[-1]
        queries = tokens[:-1]
        for ans in camel_match(queries, pattern):
            print("true" if ans else "false")

if __name__ == '__main__':
    main()