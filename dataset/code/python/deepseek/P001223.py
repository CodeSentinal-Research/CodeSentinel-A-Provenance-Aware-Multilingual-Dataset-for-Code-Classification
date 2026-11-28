def countBinStrings(N):
    count_0s, count_1s = 1, 1

    for _ in range(N - 1):
        count_0s, count_1s = count_1s, count_0s + count_1s

    return count_0s + count_1s

def main():
    N = int(input().strip())
    print(countBinStrings(N))

if __name__ == "__main__":
    main()