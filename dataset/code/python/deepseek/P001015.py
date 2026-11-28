def solve(N, K, arr):
    from collections import Counter
    counter = Counter(arr)
    return sorted(counter.keys(), key=lambda x: (-counter[x], arr.index(x)))[:K]

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(' '.join(solve(N, K, arr)))

main()
This program works by first using Python's built-in Counter class from the collections module to count the occurrences of each number in the array. It then sorts the keys of the Counter dictionary (which are the numbers from the array) in descending order based on their counts and in ascending order of their original indices in the array. The sorted keys are then printed, with their count and their original index prepended to each string. The top K most frequent elements are then selected and printed.