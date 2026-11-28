def find_position_of_only_set_bit(N):
    position = 1
    while N > 0:
        if N % 2 == 1:
            return position
        N = N // 2
        position += 1
    return -1

def main():
    N = int(input())
    print(find_position_of_only_set_bit(N))

if __name__ == "__main__":
    main()