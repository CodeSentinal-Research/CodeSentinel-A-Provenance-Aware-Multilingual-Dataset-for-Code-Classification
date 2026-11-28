def is_identity_matrix(N, A):
    for i in range(N):
        for j in range(N):
            if i == j:
                if A[i][j] != 1:
                    return False
            elif A[i][j] != 0:
                return False
    return True

def main():
    N = int(input().strip())
    A = []
    for _ in range(N):
        A.append([int(x) for x in input().strip().split()])
    print(is_identity_matrix(N, A))

if __name__ == "__main__":
    main()