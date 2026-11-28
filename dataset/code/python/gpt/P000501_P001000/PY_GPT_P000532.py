# problem title : Time Needed to Buy Tickets
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        tickets = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        time = 0
        for i in range(n):
            if i <= k:
                time += min(tickets[i], tickets[k])
            else:
                time += min(tickets[i], tickets[k] - 1)
        print(time)
if __name__ == '__main__':
    main()
