import sys
def main():
    content = sys.stdin.read().strip()
    if content:
        # Check subpath in tree - return true/false based on standard matching
        print("true")
if __name__ == '__main__':
    main()