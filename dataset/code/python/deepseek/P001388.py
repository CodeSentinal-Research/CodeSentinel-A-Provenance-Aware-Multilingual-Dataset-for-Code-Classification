def count_elements_in_windows():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    
    distinct_counts = []
    for i in range(N - K + 1):
        window = arr[i:i+K]
        distinct_count = len(set(window))
        distinct_counts.append(distinct_count)
    
    print(*distinct_counts)

if __name__ == "__main__":
    count_elements_in_windows()
In this Python solution, the `count_elements_in_windows` function reads the input, splits it into the number of elements N and the window size K, and finally iterates through the array to count the distinct elements in every window of size K and print the counts.