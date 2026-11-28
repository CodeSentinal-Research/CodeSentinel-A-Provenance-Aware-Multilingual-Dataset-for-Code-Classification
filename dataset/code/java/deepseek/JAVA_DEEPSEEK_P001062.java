import java.util.*;

public class Main {
    static class Edge {
        int to;
        int cost;
        Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }
    static class Vertex {
        int inDegree = 0;
        List<Edge> edges = new ArrayList<>();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        List<Vertex> vertices = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            vertices.add(new Vertex());
        }
        for(int i = 0; i < M; i++) {
            int from = scanner.nextInt() - 1;
            int to = scanner.nextInt() - 1;
            int cost = scanner.nextInt();
            vertices.get(from).edges.add(new Edge(to, cost));
        }
        int count = 0;
        for(Vertex vertex : vertices) {
            if(vertex.inDegree == 0) {
                count++;
            }
        }
        System.out.println(count);
    }
}
