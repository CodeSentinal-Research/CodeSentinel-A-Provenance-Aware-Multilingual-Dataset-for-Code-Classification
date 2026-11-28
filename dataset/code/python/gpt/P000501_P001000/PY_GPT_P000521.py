# problem title : Increasing Order Removal
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        passes = 0
        while nums:
            passes += 1
            rem = []
            last = -float('inf')
            for x in nums:
                if x > last:
                    last = x
                else:
                    rem.append(x)
            nums = rem
        print(passes)
if __name__ == '__main__':
    main()
