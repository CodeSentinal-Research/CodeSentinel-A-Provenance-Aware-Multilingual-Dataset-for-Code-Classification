def maxScore(N, K, nums):
    max_score = float('-inf')

    d = [(0, 0)]

    for i in range(1, N):
        while d and i - d[0][1] >= K:
            d.popleft()
        if d:
            max_score = max(max_score, d[0][0] + nums[i])
        d.append((nums[i] + d[0][0], i))

    return max_score


def main():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))
    print(maxScore(N, K, nums))


if __name__ == '__main__':
    main()

This Python solution uses a priority queue to track the elements with the highest scores. It does so by storing tuples, each containing the score and the index. When we attempt to jump, if the index within the range, we pop elements from the queue until we reach the next element within K steps. The highest score we can get at each index is updated if necessary.