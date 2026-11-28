def combinationSum3(k, n):
    def backtrack(start, target, k, buffer):
        if len(buffer) == k and target == 0:
            results.append(buffer)
            return
        if len(buffer) > k or target < 0:
            return
        for i in range(start, 10):
            if i not in buffer:
                backtrack(i + 1, target - i, k, buffer + [i])

    results = []
    backtrack(1, n, k, [])
    return results

def main():
    k = int(input().strip())
    n = int(input().strip())
    result = combinationSum3(k, n)
    for r in result:
        print(r)

if __name__ == '__main__':
    main()