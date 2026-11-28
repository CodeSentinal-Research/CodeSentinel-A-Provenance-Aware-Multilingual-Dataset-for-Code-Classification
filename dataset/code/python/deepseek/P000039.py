def find_ascii_value():
    c = input("Enter a printable character: ")
    if len(c) > 1:
        print("Please enter only one character.")
    else:
        print(f"The ASCII value of {c} is {ord(c)}")

find_ascii_value()