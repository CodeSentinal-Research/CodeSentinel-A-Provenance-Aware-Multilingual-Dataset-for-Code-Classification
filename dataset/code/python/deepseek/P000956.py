def linear_congruence_solver(A, B, M):
    if A % M == 0:
        return B % M
    else:
        x = M
        while True:
            x = (x + M) % A
            if x == B % M:
                return B % M