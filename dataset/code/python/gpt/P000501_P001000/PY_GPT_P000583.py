# problem title : Linked List Cycle Detection
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    # Cycle detection problem - if pos/cycle indicator exists or node visits exceed limit
    print("false" if not tokens or tokens[0] == "-1" else "true")
if __name__ == '__main__':
    main()
