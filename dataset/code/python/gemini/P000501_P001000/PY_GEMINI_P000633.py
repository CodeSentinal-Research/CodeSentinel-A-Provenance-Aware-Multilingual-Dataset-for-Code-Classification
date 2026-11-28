import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        # If serialized list is given or n elements
        if len(tokens) > 1 and tokens[0].isdigit() and int(tokens[0]) == len(tokens) - 1:
            print(*(tokens[1:]))
        else:
            print(*(tokens))
if __name__ == '__main__':
    main()