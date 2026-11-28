# problem title : Tower of Hanoi
# Solve the stated task using standard input and standard output.
import sys
def hanoi(n, src, dst, aux):
    if n == 1:
        print(f"Move disk 1 from {src} to {dst}")
        return
    hanoi(n - 1, src, aux, dst)
    print(f"Move disk {n} from {src} to {dst}")
    hanoi(n - 1, aux, dst, src)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        hanoi(n, 'A', 'C', 'B')
        print(2**n - 1)
if __name__ == '__main__':
    main()
