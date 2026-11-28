def hanoi(n, source, target, auxiliary):
    if n > 0:
        hanoi(n - 1, source, auxiliary, target)

        print('Move disk', n, 'from', source, 'to', target)

        hanoi(n - 1, auxiliary, target, source)

def main():
    n = int(input("Enter the number of disks: "))
    hanoi(n, 'A', 'B', 'C')

if __name__ == "__main__":
    main()
In this Python solution, the function hanoi(n, source, target, auxiliary) is used to calculate the solution. First, it recursively calls itself to move the top n-1 disks from source to auxiliary, and then it prints the current move (source to target) and the recursive call to move the remaining disks from auxiliary to target. After the recursive call, it will finally move the nth disk from source to target, and it will again recursively call the hanoi function to move the n-1 disks left on auxiliary to target.

In the main function, we get the number of disks from the user input, and then call the hanoi function with these parameters.