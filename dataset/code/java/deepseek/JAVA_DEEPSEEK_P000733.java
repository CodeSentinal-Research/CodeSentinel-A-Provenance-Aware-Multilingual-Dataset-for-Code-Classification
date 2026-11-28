import java.util.*;

public class Main {
    private int V;
    private int E;
    private int M;
    private ArrayList<ArrayList<Integer>> adjList;

    public Main(int V, int E, ArrayList<ArrayList<Integer>> adjList, int M) {
        this.V = V;
        this.E = E;
        this.adjList = adjList;
        this.M = M;
    }

    public boolean graphColoring() {
        int[] color = new int[V];
        Arrays.fill(color, -1);
        return solve(0, color);
    }

    private boolean solve(int node, int[] color) {
        if (node == V) {
            return true;
        }
        for (int c = 1; c <= M; c++) {
            if (isValid(node, c, color)) {
                color[node] = c;
                if (solve(node + 1, color)) {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }

    private boolean isValid(int node, int color, int[] colors) {
        for (int i = 0; i < V; i++) {
            if (adjList.get(node).get(i) == 1 && colors[i] == color) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int V = scanner.nextInt();
        int E = scanner.nextInt();
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
            for (int j = 0; j < V; j++) {
                adjList.get(i).add(scanner.nextInt());
            }
        }
        int M = scanner.nextInt();
        Main main = new Main(V, E, adjList, M);
        System.out.println(main.graphColoring());
    }
}
