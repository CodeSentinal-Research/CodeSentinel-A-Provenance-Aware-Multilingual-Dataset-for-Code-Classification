# problem title : Verify Preorder Serialization of a Binary Tree
# Solve the stated task using standard input and standard output.
import sys
def main():
    s = sys.stdin.read().strip()
    if s:
        slots = 1
        for node in s.split(','):
            slots -= 1
            if slots < 0:
                print("false")
                return
            if node != '#':
                slots += 2
        print("true" if slots == 0 else "false")
if __name__ == '__main__':
    main()
