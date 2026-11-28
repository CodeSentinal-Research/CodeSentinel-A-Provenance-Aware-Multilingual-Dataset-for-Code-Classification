def find_transition_point():
    N = int(input())
    arr = list(map(int, input().split()))

    for i in range(N):
        if arr[i] == 1:
            return i

    return -1

if __name__ == "__main__":
    print(find_transition_point())