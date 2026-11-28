def calculate_percentage():
    scored = int(input("Enter marks scored: "))
    total = int(input("Enter total marks: "))

    if scored < 0 or total < 0 or scored > 1000 or total > 1000:
        print("Invalid input! Marks scored and total must be between 0 and 1000.")
        return

    percentage = (scored / total) * 100
    print("Percentage: ", percentage)

calculate_percentage()