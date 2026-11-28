Here is the python code for the problem:

def time_needed_to_buy_tickets(n, tickets, k):
    queue = [0]*n
    queue[k] = 1
    time = 0

    while sum(queue) > 0:
        for i in range(n):
            queue[i] += 1
            if queue[i] % 2 == 0:
                if i != k or sum(queue[i+1:]) == 0:
                    queue[i] = 0
                else:
                    queue[i] = -1

        time += 1

    return time

def main():
    n = int(input("Enter number of people: "))
    tickets = list(map(int, input("Enter the number of tickets each person needs: ").split()))
    k = int(input("Enter the index of person to finish buying tickets: "))
    print(time_needed_to_buy_tickets(n, tickets, k))

if __name__ == "__main__":
    main()

In this code, the time complexity is O(n) because we are iterating through each person and ticket in the queue once.

Please note that the problem statement does not provide the input for the number of people and the index of the person to finish buying tickets. So, in this case, it will not work. To solve this problem, you need to provide the input in the main function as well as it's not mentioned in the problem statement.