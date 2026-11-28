Here is the Python code to solve the problem:

def tour(petrol, distance, start=0):
    n = len(petrol)
    if n == 1:
        return start if petrol[start] >= distance[start] else -1

    total_petrol = petrol[start]
    current_petrol = petrol[start]
    next_node = (start + 1) % n

    while True:
        if current_petrol >= distance[next_node]:
            total_petrol += -current_petrol + petrol[next_node]
            current_petrol = petrol[next_node]
            next_node = (next_node + 1) % n
            if next_node == start:
                return start if total_petrol >= distance[start] else -1
        else:
            current_petrol += petrol[start]
            start = next_node
            if current_petrol < distance[start]:
                return -1

This code first checks if the number of petrol pumps is 1. If so, it returns the starting point if the first petrol pump has enough petrol to travel to the next pump.

For multiple petrol pumps, it calculates the total amount of petrol that can be collected from the first petrol pump, and then it subtracts the petrol from the first petrol pump and adds the petrol from the next one. If the next one has enough petrol to travel to the first, it continues. If not, it returns -1.

The `start` parameter is used to start the tour from the given point. If not provided, it defaults to 0. The `next_node` variable is used to keep track of the next petrol pump to visit.