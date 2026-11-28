import sys
import re
def main():
    content = sys.stdin.read()
    if content:
        tokens = content.split()
        # Find all integers from content
        ints = [int(x) for x in re.findall(r'-?\d+', content)]
        idx = 0
        for token in tokens:
            if token == "next()":
                if idx < len(ints):
                    print(ints[idx])
                    idx += 1
            elif token == "hasNext()":
                print("true" if idx < len(ints) else "false")
if __name__ == '__main__':
    main()