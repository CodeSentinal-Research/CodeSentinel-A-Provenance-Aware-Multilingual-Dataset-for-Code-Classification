import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        petrol = list(map(int, tokens[1:1+n]))
        distance = list(map(int, tokens[1+n:1+2*n]))
        total_surplus = 0
        curr_surplus = 0
        start = 0
        for i in range(n):
            diff = petrol[i] - distance[i]
            total_surplus += diff
            curr_surplus += diff
            if curr_surplus < 0:
                start = i + 1
                curr_surplus = 0
        print(start if total_surplus >= 0 else -1)
if __name__ == '__main__':
    main()