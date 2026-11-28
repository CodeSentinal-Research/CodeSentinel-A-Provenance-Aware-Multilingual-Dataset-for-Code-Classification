def get_minimum_element():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))

    min_element = min(arr[:K])
    print(min_element)

    for i in range(K, N):
        arr.pop(0)
        arr.append(arr[i])
        min_element = min(arr)
        print(min_element)

get_minimum_element()