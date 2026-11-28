Here is the Python code for the problem:

def destination_city():
    N = int(input().strip())
    for _ in range(N):
        source, destination = input().strip().split()
    for i in range(N):
        if input() != source:
            print(destination)
            break
    else:
        print(source)

def main():
    destination_city()

if __name__ == "__main__":
    main()

In this code, we first read the number of lines `N` from the input. Then we read `N` pairs of source and destination city. For each pair, we check if the destination city is not in the list of source cities. If it is not in the list, we print the destination city. If it is in the list, we print the source city.