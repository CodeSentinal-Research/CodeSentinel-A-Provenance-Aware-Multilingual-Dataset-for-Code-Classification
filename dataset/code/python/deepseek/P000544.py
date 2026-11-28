def openLock(deadends, target):
    visited = set(deadends)
    queue = ['0000']
    steps = 0

    while queue:
        steps += 1
        for _ in range(len(queue)):
            cur = queue.pop(0)
            if cur == target:
                return steps
            for i in range(4):
                for dir in [-1, 1]:
                    nxt = cur[:i] + str((int(cur[i]) + dir)) % 10 + cur[i + 1:]
                    if nxt not in visited:
                        visited.add(nxt)
                        queue.append(nxt)
In this Python code, we use a BFS approach to find the minimum number of moves to reach the target combination from the initial state '0000'. We use a queue to store all the states that we haven't visited yet, and a set to store all the deadends. We initialize the queue with the initial state '0000' and the visited set with the deadends. Then, we start a loop that will continue until the queue is empty. In each iteration of the loop, we pop a state from the queue and check if it is the target state. If it is, we return the current number of steps. Otherwise, we generate all possible states by rotating one wheel one position forward or backward and add them to the queue if they haven't been visited yet.