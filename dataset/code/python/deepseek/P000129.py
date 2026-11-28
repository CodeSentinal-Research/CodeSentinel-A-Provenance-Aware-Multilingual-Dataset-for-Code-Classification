def solve(n, arr):
    stack = []
    result = [-1] * n

    for i in range(n - 1, -1, -1):
        while stack and arr[i] >= arr[stack[-1]]:
            stack.pop()

        if stack:
            result[i] = arr[stack[-1]]

        stack.append(i)

    return result


def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))

    result = solve(n, arr)
    print(*result)


if __name__ == "__main__":
    main()