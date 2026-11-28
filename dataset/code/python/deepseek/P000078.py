Here is a Python solution for the problem:

def convert_days(days):
    DAYS_IN_YEAR = 365
    DAYS_IN_WEEK = 7

    years = days // DAYS_IN_YEAR
    days %= DAYS_IN_YEAR

    weeks = days // DAYS_IN_WEEK
    days %= DAYS_IN_WEEK

    return years, weeks, days

def main():
    days = int(input("Enter the number of days: "))
    if 1 <= days <= 100000:
        years, weeks, remaining_days = convert_days(days)
        print(f'Years: {years}, Weeks: {weeks}, Remaining Days: {remaining_days}')
    else:
        print("Invalid input, please enter a positive integer between 1 and 100000.")

if __name__ == "__main__":
    main()

In this code, the function `convert_days` takes a number of days and converts it to years and weeks. The number of remaining days is then printed out. The `main` function is responsible for getting the input, validating it, and calling the `convert_days` function.