def count_distinct_elements():
    N, Q = map(int, input().split())
    arr = set(map(int, input().split()))

    for _ in range(Q):
        index, new_value = map(int, input().split())
        arr.remove(arr & {index})
        arr.add(index)
        print(len(arr))

count_distinct_elements()