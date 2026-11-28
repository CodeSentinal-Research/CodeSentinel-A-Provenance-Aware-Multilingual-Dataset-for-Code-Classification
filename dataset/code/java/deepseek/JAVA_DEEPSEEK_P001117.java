import java.util.*;

public class Main {
    static class Graph {
        List<List<Integer>> adjList;
        int V;

        Graph(int V) {
            this.V = V;
            adjList = new ArrayList<>();
            for (int i = 0; i < V; i++) {
                adjList.add(i, new ArrayList<>());
            }
        }

        void addEdge(int u, int v) {
            adjList.get(u).add(v);
        }

        void cloneGraph(Graph graph, int s, HashMap<Integer, Integer> visited) {
            visited.put(s, 1);
            for (int i : graph.adjList.get(s)) {
                if (!visited.containsKey(i)) {
                    cloneGraph(graph, i, visited);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt();
        Graph graph = new Graph(V);
        for (int i = 0; i < V; i++) {
            int E = sc.nextInt();
            for (int j = 0; j < E; j++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                graph.addEdge(u, v);
            }
        }
        HashMap<Integer, Integer> visited = new HashMap<>();
        graph.cloneGraph(graph, 0, visited);
        for (int i = 0; i < V; i++) {
            for (int j : graph.adjList.get(i)) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
