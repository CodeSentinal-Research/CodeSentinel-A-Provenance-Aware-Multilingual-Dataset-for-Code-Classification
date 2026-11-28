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

        public void addEdge(int u, int v) {
            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }

        public Graph cloneGraph() {
            Graph clone = new Graph(V);
            Queue<Integer> q = new LinkedList<>();
            boolean[] visited = new boolean[V];
            for (int i = 0; i < V; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.add(i);
                    while (!q.isEmpty()) {
                        int node = q.poll();
                        clone.adjList.get(node).addAll(adjList.get(node));
                        for (int neighbour : adjList.get(node)) {
                            if (!visited[neighbour]) {
                                visited[neighbour] = true;
                                q.add(neighbour);
                            }
                        }
                    }
                }
            }
            return clone;
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
        Graph clone = graph.cloneGraph();
        for (int i = 0; i < V; i++) {
            System.out.println(clone.adjList.get(i));
        }
    }
}
