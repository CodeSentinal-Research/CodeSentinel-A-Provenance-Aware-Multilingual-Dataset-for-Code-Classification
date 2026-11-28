def min_difference_highest_lowest(scores, K):
    scores.sort()
    return min(scores[n-K] - scores[K-1] for n in range(K, len(scores)+K))

def main():
    N, K = map(int, input().split())
    scores = list(map(int, input().split()))
    print(min_difference_highest_lowest(scores, K))

if __name__ == "__main__":
    main()