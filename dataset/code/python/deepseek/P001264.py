Here is the Python code to solve the problem:

def main():
    N = int(input().strip())
    tasks = []
    for _ in range(N):
        energy, min_energy = map(int, input().strip().split())
        tasks.append((energy, min_energy))
    tasks.sort()
    min_energy = tasks[0][1]
    total_energy = min_energy
    for task in tasks[1:]:
        if total_energy + task[0] >= task[1]:
            total_energy += task[0]
        else:
            total_energy = task[1]
    print(total_energy)

if __name__ == "__main__":
    main()

This code first reads the number of tasks and the energy needed for each task. It then sorts the tasks by the minimum energy needed. For each task, it checks if adding the energy needed for the current task would increase the total energy to a point where it is greater than or equal to the minimum energy required for the next task. If it can, it adds the energy needed for the current task to the total energy. If it can't, it sets the total energy to the minimum energy required for the next task.