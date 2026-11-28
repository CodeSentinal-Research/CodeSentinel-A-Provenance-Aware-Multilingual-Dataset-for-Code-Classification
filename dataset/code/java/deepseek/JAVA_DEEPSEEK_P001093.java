import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < N; i++) {
            int M1 = scanner.nextInt();
            scanner.nextLine();

            Graph graph1 = new Graph(M1);
            for (int j = 0; j < M1; j++) {
                String[] vertices = scanner.nextLine().split(" ");
                graph1.addEdge(Integer.parseInt(vertices[0]), Integer.parseInt(vertices[1]));
            }

            int M2 = scanner.nextInt();
            scanner.nextLine();

            Graph graph2 = new Graph(M2);
            for (int j = 0; j < M2; j++) {
                String[] vertices = scanner.nextLine().split(" ");
                graph2.addEdge(Integer.parseInt(vertices[0]), Integer.parseInt(vertices[1]));
           
            }

            if (graph1.isIsomorphic(graph2)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}

class Graph {
    private int[][] adjacencyMatrix;
    private int numVertices;

    public Graph(int numVertices) {
        this.numVertices = numVertices;
        adjacencyMatrix = new int[numVertices][numVertices];
    }

    public void addEdge(int v1, int v2) {
        adjacencyMatrix[v1][v2] = 1;
        adjacencyMatrix[v2][v1] = 1;
    }

    public boolean isIsomorphic(Graph other) {
        if (this.numVertices != other.numVertices) {
            return false;
        }

        for (int i = 0; i < this.numVertices; i++) {
            for (int j = 0; j < this.numVertices; j++) {
                if (this.adjacencyMatrix[i][j] != other.adjacencyMatrix[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
}
