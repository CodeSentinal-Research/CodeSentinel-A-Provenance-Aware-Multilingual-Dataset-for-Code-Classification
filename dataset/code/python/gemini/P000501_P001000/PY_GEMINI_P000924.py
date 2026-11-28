def decimal_to_binary(n: int) -> str:
    if n == 0:
        return "0"
    return bin(n)[2:]

if __name__ == '__main__':
    n = int(input())
    print(decimal_to_binary(n))