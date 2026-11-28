import sys


def main():
    input_data = sys.stdin.read().split()
    if len(input_data) >= 2:
        a = int(input_data[0])
        b = int(input_data[1])

        # Swap the two numbers
        a, b = b, a

        print(a, b)


if __name__ == "__main__":
    main()