Here is the Python code:

def reconstruct_queue(people):
    people.sort(key=lambda x: (-x[0], x[1]))
    queue = []
    for person in people:
        queue.insert(person[1], person)
    return queue

def main():
    N = int(input().strip())
    people = []
    for _ in range(N):
        height, count = map(int, input().strip().split())
        people.append((height, count))
    reconstructed_queue = reconstruct_queue(people)
    print(reconstructed_queue)

if __name__ == "__main__":
    main()

This code takes in the number of people as input, and then for each person, it takes in their height and the number of people in front with a height greater than or equal to theirs as input. It then prints the reconstructed queue.