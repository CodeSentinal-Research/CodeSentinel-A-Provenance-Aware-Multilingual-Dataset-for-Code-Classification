def power_recursive(base, exponent, mod):
    if exponent == 0:
        return 1
    elif exponent % 2 == 0:
        half_exp = power_recursive(base, exponent // 2, mod)
        return (half_exp * half_exp) % mod
    else:
        return (base * power_recursive(base, exponent - 1, mod)) % mod


def main():
    base = int(input("Enter the base: "))
    exponent = int(input("Enter the exponent: "))
    mod = int(input("Enter the mod: "))
    print(power_recursive(base, exponent, mod))


if __name__ == '__main__':
    main()