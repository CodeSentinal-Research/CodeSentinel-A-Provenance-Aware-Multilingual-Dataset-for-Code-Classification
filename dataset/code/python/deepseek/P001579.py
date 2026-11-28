def max_negatives(arr, k):
    negatives = [a for a in arr if a < 0]
    negatives.sort()
    return len(negatives[:min(k, len(negatives))])

if __name__ == "__main__":
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(max_negatives(arr, K))