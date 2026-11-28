def print_lower_triangular(N):
    for i in range(N):
        for j in range(i+1, N):
            print(" ", end="")
        for k in range(i+1, N):
            print("*", end=" ")
        print()

def main():
    N = int(input())
    print_lower_triangular(N)

if __name__ == "__main__":
    main()