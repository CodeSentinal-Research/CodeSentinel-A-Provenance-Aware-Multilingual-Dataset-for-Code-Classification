def convert_seconds(seconds):
    if seconds < 0 or seconds > 86400:
        return "Invalid input. Please enter a non-negative integer between 0 and 86400."

    hours = seconds // 3600
    seconds %= 3600

    minutes = seconds // 60
    seconds %= 60

    return f"{hours}:{minutes}:{seconds}"

def main():
    seconds = int(input("Enter a non-negative integer between 0 and 86400: "))
    print(convert_seconds(seconds))

if __name__ == "__main__":
    main()