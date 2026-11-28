def convert_between_arbitrary_bases(number_str, base_A, base_B):
    if not (2 <= base_A <= base_B <= 36) or not (1 <= len(number_str) <= 100):
        return "Invalid input"

    def base_A_to_base_10(number_str, base_A):
        return int(number_str, base_A)

    def base_10_to_base_B(number_int, base_B):
        if number_int < base_B:
            return str(number_int)
        else:
            return base_10_to_base_B(number_int // base_B, base_B) + str(number_int % base_B)

    number_int = base_A_to_base_10(number_str, base_A)
    return base_10_to_base_B(number_int, base_B)


def main():
    number_str = input("Enter a number in base A (2 to 36): ")
    base_A = int(input("Enter base A (2 to 36): "))
    base_B = int(input("Enter base B (2 to 36): "))

    print(convert_between_arbitrary_bases(number_str, base_A, base_B))


if __name__ == "__main__":
    main()