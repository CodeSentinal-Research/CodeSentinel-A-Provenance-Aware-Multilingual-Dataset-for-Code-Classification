def solve(pattern, queries):
    for query in queries:
        if query == pattern:
            print("YES")
        else:
            print("NO")

def main():
    n = int(input().strip())
    pattern = input().strip()
    queries = [input().strip() for _ in range(n)]
    solve(pattern, queries)

if __name__ == "__main__":
    main()