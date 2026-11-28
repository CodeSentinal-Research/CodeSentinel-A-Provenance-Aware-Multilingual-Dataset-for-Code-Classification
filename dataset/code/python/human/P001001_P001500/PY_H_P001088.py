import networkx as nx
import collections
import json
import sys

def solve(G, k):
    """
    Check if the graph is a connected tree where every vertex has at most 2 vertices at distance exactly k.
    """
    n = G.number_of_nodes()
    if n == 0:
        return True  # vacuously true for empty graph

    # Condition 1: connected
    if not nx.is_connected(G):
        return False

    # Condition 2: acyclic (tree)
    if G.number_of_edges() != n - 1:
        return False

    # Condition 3: for every vertex v, number of vertices at distance exactly k <= 2
    for v in G.nodes():
        # BFS from v to compute distances
        dist = {v: 0}
        queue = collections.deque([v])
        while queue:
            curr = queue.popleft()
            for neighbor in G.neighbors(curr):
                if neighbor not in dist:
                    dist[neighbor] = dist[curr] + 1
                    queue.append(neighbor)
        # Count vertices at distance k
        count = sum(1 for d in dist.values() if d == k)
        if count > 2:
            return False
    return True

if __name__ == "__main__":
    import sys
    import json

    def parse_input(s: str) -> dict:
        s = s.strip()
        if s.lower() == "none" or s == "":
            return {}
        result = {}
        pairs = s.split(',')
        for pair in pairs:
            key, value = pair.strip().split('=')
            # For this task, k is an integer
            result[key] = int(value)
        return result

    test_file = sys.argv[1] if len(sys.argv) > 1 else "edgelists/connected_acyclic_distance_k_check.edge_list"

    with open(test_file, "r") as f:
        test_cases = json.load(f)

    for key, case in test_cases.items():
        if case["directed"]:
            G = nx.DiGraph()
        else:
            G = nx.Graph()
        G.add_nodes_from(case["nodes"])
        if case["weighted"]:
            G.add_weighted_edges_from(case["edges"])
        else:
            G.add_edges_from(case["edges"])
        params = parse_input(case.get("input", "none"))
        result = solve(G, **params)
        case["label"] = result

    with open(test_file, "w") as f:
        json.dump(test_cases, f, indent=2, default=str)