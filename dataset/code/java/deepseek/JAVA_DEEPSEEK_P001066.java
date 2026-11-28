import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        String[] nm = br.readLine().split(" ");
        int N = Integer.parseInt(nm[0]);
        int M = Integer.parseInt(nm[1]);
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            String[] edge = br.readLine().split(" ");
            int u = Integer.parseInt(edge[0]) - 1;
            int v = Integer.parseInt(edge[1]) - 1;
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        int V = Integer.parseInt(br.readLine()) - 1;
        List<Integer> neighbors = new ArrayList<>();
        for (int neighbor : graph.get(V)) {
            neighbors.add(neighbor);
        }
        neighbors.sort(Integer::compareTo);
        for (int neighbor : neighbors) {
            out.println(neighbor + 1);
        }
        out.close();
    }
}
