def grayCode(n):
    def generateGray(n, binary):
        if n == 0:
            print(binary)
            return

        generateGray(n - 1, binary + "0")

        if n != 1:
            generateGray(n - 1, binary + "1")

    for i in range(n):
        generateGray(n, "")

def main():
    n = int(input("Enter the number of bits for the gray code: "))
    if 1 <= n <= 16:
        grayCode(n)
    else:
        print("Invalid input. Please enter a number between 1 and 16.")

if __name__ == "__main__":
    main()