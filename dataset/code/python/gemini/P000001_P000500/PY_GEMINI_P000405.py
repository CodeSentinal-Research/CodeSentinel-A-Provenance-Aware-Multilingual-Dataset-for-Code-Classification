import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        courses = []
        idx = 1
        for _ in range(n):
            courses.append((tokens[idx], tokens[idx+1]))
            idx += 2
        inst = tokens[idx]
        for c, i in courses:
            if i == inst:
                print(c)
if __name__ == '__main__':
    main()