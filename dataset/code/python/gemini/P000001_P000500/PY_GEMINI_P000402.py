import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        flights = []
        idx = 1
        for _ in range(n):
            flight = tokens[idx]
            dest = tokens[idx+1]
            flights.append((flight, dest))
            idx += 2
        target_dest = tokens[idx]
        for flight, dest in flights:
            if dest == target_dest:
                print(flight)

if __name__ == '__main__':
    main()