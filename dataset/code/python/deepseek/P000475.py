def find_position(target):
    try:
        target = int(target)
    except ValueError:
        return -1

    return target

def main():
    target = input("Enter a target number: ")
    position = find_position(target)

    if position != -1:
        print(f"The target is at index {position}")
    else:
        print("Target not found in the array")

if __name__ == "__main__":
    main()