def min_window():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    deque = []
    res = float('inf')
    for i in range(N):
        while deque and deque[-1] < A[i]:
            deque.pop()
        deque.append(A[i])
        if i >= K-1:
            if deque[0] == A[i-K+1]:
                deque.popleft()
            if deque:
                res = min(res, deque[0])
    print(res)

if __name__ == '__main__':
    min_window()