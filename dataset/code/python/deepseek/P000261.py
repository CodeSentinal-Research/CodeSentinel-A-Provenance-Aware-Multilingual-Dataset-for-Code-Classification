def toggle_case(s):
    return ''.join(char.upper() if char.islower() else char.lower() for char in s)

if __name__ == "__main__":
    s = input("Enter a string: ")
    print(toggle_case(s))