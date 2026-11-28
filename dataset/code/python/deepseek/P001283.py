Here is the Python code for the problem:

def reconstruct_queue(people):
    result = []

    people.sort(key=lambda x: (-x[0], x[1]))

    for person in people:
        result.insert(person[1], person)

    return result


def main():
    N = int(input())

    people = []
    for i in range(N):
        line = input().split()
        people.append((int(line[0]), int(line[1])))

    result = reconstruct_queue(people)

    for person in result:
        print(person[0], person[1])


if __name__ == "__main__":
    main()

This code reads the number of people from the input, and then reads each person's height and count. It then reconstructs the queue based on the sorted height and count of the people. The reconstructed queue is then printed.