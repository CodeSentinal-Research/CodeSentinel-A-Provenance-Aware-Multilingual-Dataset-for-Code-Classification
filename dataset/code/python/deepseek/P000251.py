def reverse_string(s):
    return s[::-1]

def main():
    s = input("Enter a string: ")
    reversed_string = reverse_string(s)
    print("Reversed String: ", reversed_string)

if __name__ == "__main__":
    main()