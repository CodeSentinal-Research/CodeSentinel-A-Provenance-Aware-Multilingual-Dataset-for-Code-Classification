def main():
    N = int(input().strip())
    words = [input().strip() for _ in range(N)]
    alphabet = input().strip()

    for i in range(N - 1):
        if words[i] == words[i + 1]:
            if len(words[i]) > len(words[i + 1]) and alphabet[len(words[i]) - 1] <= alphabet[len(words[i + 1]) - 1]:
                print("NO")
                return
    print("YES")

if __name__ == "__main__":
    main()