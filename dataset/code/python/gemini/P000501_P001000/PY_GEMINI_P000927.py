def convert_base(num_str: str, from_base: int, to_base: int) -> str:
    val = int(num_str, from_base)
    if val == 0:
        return "0"
    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    res = []
    while val > 0:
        res.append(digits[val % to_base])
        val //= to_base
    return "".join(reversed(res))

if __name__ == '__main__':
    s, b1, b2 = input().split()
    print(convert_base(s, int(b1), int(b2)))