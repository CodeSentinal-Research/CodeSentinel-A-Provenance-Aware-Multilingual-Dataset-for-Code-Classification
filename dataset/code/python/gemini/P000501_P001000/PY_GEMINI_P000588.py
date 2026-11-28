import sys
def main():
    content = sys.stdin.read().strip()
    if content:
        print(content)
if __name__ == '__main__':
    main()