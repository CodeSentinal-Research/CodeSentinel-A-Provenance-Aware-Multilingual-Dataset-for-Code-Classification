Here's the Python code:

from collections import defaultdict
def findItinerary(tickets):
    graph = defaultdict(list)
    for start, end in sorted(tickets)[::-1]:
        graph[start].append(end)
        if len(graph[start]) == 1:
            graph[start][0] = 'start'
        else:
            graph[start][-1] = 'end'
        if len(graph[start]) > 2:
            del graph[start][-1]
    route, stack = [], [('start', [])]
    while stack:
        if not route or route[-1] == 'start':
            cur = stack[-1]
            stack.pop()
            for neighbor in sorted(graph[cur[0]]):
                if graph[cur[0]][0] == 'start':
                    graph[cur[0]][0] = neighbor
                if len(graph[cur[0]]) > 2:
                    del graph[cur[0]][-1]
                stack.append((neighbor, graph[cur[0]]))
        else:
            route.append(cur[0])
            graph[cur[0]].pop(0)
            if len(graph[cur[0]]) == 0:
                del stack[-1]
    return route

def main():
    N = int(input())
    tickets = []
    for _ in range(N):
        departure, arrival = input().split()
        tickets.append((departure, arrival))
    print(findItinerary(tickets))

if __name__ == "__main__":
    main()

This code constructs a directed graph from the input tickets, then uses the depth-first search to find the itinerary. The main function is the entry point of the program. It first reads the number of tickets, then reads the list of tickets. The `findItinerary` function is the core of the solution. It constructs a graph from the tickets, then uses depth-first search to find the itinerary. Finally, it prints the reconstructed itinerary.