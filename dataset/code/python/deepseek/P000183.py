def count_distinct_elements():
    N, K = map(int, input().split())
    numbers = list(map(int, input().split()))

    for i in range(N-K+1):
        window = numbers[i:i+K]
        print(len(set(window)))

count_distinct_elements()

This python program reads an input string that contains two numbers N and K, followed by N numbers. It then creates a list of numbers from the input string, and for every window of size K, it prints the count of distinct elements in that window.