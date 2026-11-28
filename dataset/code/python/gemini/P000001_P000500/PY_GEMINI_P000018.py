import sys

def main():
    lines = sys.stdin.read().split()
    if lines:
        year = int(lines[0])
        is_leap = (year % 400 == 0) or (year % 4 == 0 and year % 100 != 0)
        print("Leap Year" if is_leap else "Not a Leap Year")

if __name__ == '__main__':
    main()