Here is the Python code for the problem:

def generate_sequences(target):
    def dfs(path, index):
        if sum(path) == target and len(path) == n:
            sequences.append(path)
            return
        for i in range(index, n+1):
            dfs(path + [i], i)
    
    sequences = []
    n = 6  
    dfs([], 1)
    return sequences

target = int(input("Enter the target sum: "))
sequences = generate_sequences(target)
for sequence in sequences:
    print(sequence)

In this code, a depth-first search is used to explore all possible combinations of dice rolls that sum up to the target. The depth-first search is performed on each new roll, starting from the first roll (index 1). The function dfs is a helper function that performs the depth-first search.

The main function is a simple usage example. It first prompts the user for the target sum, then calls the generate_sequences function with this sum, and finally prints the generated sequences.