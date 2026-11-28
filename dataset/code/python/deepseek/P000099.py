Here's a Python code snippet that does what you're asking for:

def floyd_triangle(n):
    num = 1
    for i in range(n):
        for j in range(i+1):
            print(num, end=' ')
            num += 1
        print("\n")

def main():
    n = int(input("Enter the number of rows: "))
    floyd_triangle(n)

if __name__ == "__main__":
    main()

This code first asks for the number of rows, and then prints the Floyd's triangle with that many rows. Each row starts with the number 1 and increases by 1 for each number on the next line. The `print("\n")` statement at the end of each row is used to start a new line.