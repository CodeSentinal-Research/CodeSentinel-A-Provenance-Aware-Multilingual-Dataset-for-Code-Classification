def intersection(M, N):
    set_m = set(M)
    set_n = set(N)
    return list(set_m & set_n)

def main():
    M, N = map(int, input().split())
    M_list = list(map(int, input().split()))
    N_list = list(map(int, input().split()))
    print(intersection(M_list, N_list))

if __name__ == "__main__":
    main()