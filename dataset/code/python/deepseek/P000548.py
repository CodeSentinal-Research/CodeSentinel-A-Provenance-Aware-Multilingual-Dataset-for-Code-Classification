def min_buses(routes, source, target):
    queue = [source]
    buses = [source]
    
    visited = set()
    visited.add(source)
    
    while queue:
        current_bus = queue.pop(0)
        
        if current_bus == target:
            return len(buses) - 1
        
        next_buses = [current_bus]
        for next_bus in routes[routes.index(current_bus)]:
            if next_bus not in visited:
                visited.add(next_bus)
                queue.append(next.bus)
                next_buses.append(next_bus)
        
        current_bus = next_buses[-1]
    
    return -1


def main():
    routes = [1, 2, 3, 4, 5]
    source = 1
    target = 5
    print(min_buses(routes, source, target))


if __name__ == "__main__":
    main()

In this code, we use a breadth-first search (BFS) to find the minimum number of buses required to reach the target from the source. We use a queue to perform the BFS, and a set to store the visited nodes. We keep adding new bus stops from the current bus until we find the target.

The main function tests the `min_buses` function with a set of routes, source, and target.