def aggressive_cows(n, stalls, k):
    def is_possible(mid):
        cows = 1
        last_cow = stalls[0]
        for i in range(1, n):
            if stalls[i] - last_cow >= mid:
                last_cow = stalls[i]
                cows += 1
                if cows == k:
                    return True
        return False

    left, right = 0, max(stalls) - min(stalls)
    while left < right:
        mid = (left + right + 1) // 2
        if is_possible(mid):
            left = mid
        else:
            right = mid - 1
    return left

def main():
    n = int(input())
    stalls = list(map(int, input().split()))
    k = int(input())
    print(aggressive_cows(n, stalls, k))

if __name__ == '__main__':
    main()