def minMutation(start, end, bank, n):
    if end not in bank:
        return -1

    queue = [(start, 0)]
    visited = set()

    while queue:
        (gene, steps) = queue.pop(0)
        if gene == end:
            return steps
        for ngene in getNeighbors(gene, bank, visited):
            queue.append((ngene, steps + 1))
            visited.add(ngene)

    return -1

def getNeighbors(gene, bank, visited):
    neighbors = []
    for i in range(len(gene)):
        for c in 'ACGT':
            newGene = gene[:i] + c + gene[i+1:]
            if newGene in bank and newGene not in visited:
                neighbors.append(newGene)
    return neighbors