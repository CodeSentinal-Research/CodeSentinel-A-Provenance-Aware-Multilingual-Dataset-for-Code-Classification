def generate_parentheses(n):
    def generate(n_left, n_right, paren_str):
        if n_left == 0 and n_right == 0:
            output.append(paren_str)
            return
        if n_left > 0:
            generate(n_left-1, n_right, paren_str+'(')
        if n_right > n_left:
            generate(n_left, n_right-1, paren_str+')')

    output = []
    generate(n, n, '')
    return output

def main():
    n = int(input("Enter the number of pairs of parentheses: "))
    while n < 1 or n > 12:
        print("Invalid input. Please enter a number between 1 and 12.")
        n = int(input("Enter the number of pairs of parentheses: "))

    print(generate_parentheses(n))

if __name__ == "__main__":
    main()