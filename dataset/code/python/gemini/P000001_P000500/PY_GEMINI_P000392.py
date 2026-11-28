import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        files = tokens[1:n+1]
        ext = tokens[n+1]
        if not ext.startswith('.'):
            ext = '.' + ext
        for f in files:
            if f.endswith(ext):
                print(f)

if __name__ == '__main__':
    main()