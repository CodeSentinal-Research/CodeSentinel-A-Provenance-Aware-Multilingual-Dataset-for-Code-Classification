import java.util.*;

class HamiltonianPath {

    static int V;
    static boolean[] visited;
    static int[] path;

    // Check if edge exists between u and v
    static boolean isSafe(int v, int[][] graph, int pos) {
        // Check if current vertex is adjacent to previous
        if (graph[path[pos - 1]][v] == 0)
            return false;

        // Check if vertex already visited
        if (visited[v])
            return false;

        return true;
    }

    static boolean solve(int[][] graph, int pos) {

        // BASE CASE: all vertices included in path
        if (pos == V)
            return true;

        // Try each vertex as next candidate
        for (int v = 0; v < V; v++) {

            if (isSafe(v, graph, pos)) {

                // CHOOSE
                path[pos] = v;
                visited[v] = true;

                // RECURSE
                if (solve(graph, pos + 1))
                    return true;

                // BACKTRACK
                path[pos] = -1;
                visited[v] = false;
            }
        }

        return false; // no vertex worked
    }

    public static void main(String[] args) {

        V = 5;

        // Adjacency matrix
        int[][] graph = {
                {0, 1, 0, 1, 0},
                {1, 0, 1, 1, 0},
                {0, 1, 0, 0, 1},
                {1, 1, 0, 0, 1},
                {0, 0, 1, 1, 0}
        };

        visited = new boolean[V];
        path = new int[V];
        Arrays.fill(path, -1);

        // Start from vertex 0
        path[0] = 0;
        visited[0] = true;

        if (solve(graph, 1)) {
            System.out.println("Hamiltonian Path found:");
            for (int v : path)
                System.out.print(v + " ");
        } else {
            System.out.println("No Hamiltonian Path exists");
        }
    }
}