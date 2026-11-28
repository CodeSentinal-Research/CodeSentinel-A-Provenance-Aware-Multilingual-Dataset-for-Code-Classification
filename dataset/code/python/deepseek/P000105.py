def count_elements():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    even_count = sum(1 for x in arr if x % 2 == 0)
    odd_count = sum(1 for x in arr if x % 2 != 0)
    print(even_count, odd_count)

count_elements()