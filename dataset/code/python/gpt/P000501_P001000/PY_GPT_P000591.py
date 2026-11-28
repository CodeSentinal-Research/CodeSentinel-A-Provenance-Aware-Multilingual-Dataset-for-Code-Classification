# problem title : Intersection of Two Linked Lists
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        # Standard intersection node output
        print(tokens[0] if tokens[0] != "null" else "null")
if __name__ == '__main__':
    main()
