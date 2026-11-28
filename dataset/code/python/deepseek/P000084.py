def check_eligibility():
    age = int(input("Enter your age: "))

    if 0 <= age <= 120:
        if age >= 18:
            print("Eligible")
        else:
            print("Not Eligible")
    else:
        print("Invalid input. Age must be between 0 and 120.")

def main():
    check_eligibility()

if __name__ == "__main__":
    main()