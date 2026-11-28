def main():
    N, K = map(int, input().split())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))

    pairs = [(a, b) for a in arr1 for b in arr2]
    pairs.sort(reverse=True)

    for pair in pairs[:K]:
        print(*pair)

if __name__ == "__main__":
    main()