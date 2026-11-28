def rearrange_array():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    positive = sorted([x for x in arr if x > 0])
    negative = sorted([x for x in arr if x < 0])
    result = []
    for i in range(n // 2):
        result.append(negative[i])
        if n % 2 == 0:
            result.append(positive[i])
        else:
            result.append(negative[i])
    if n % 2 == 1:
        result.append(positive[-1])
    print(*result)

if __name__ == "__main__":
    rearrange_array()