import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static ArrayList<ArrayList<Integer>> graph;
    static int[] disc, low, articulationPoints;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        graph = new ArrayList<>();
        disc = new int[N + 1];
        low = new int[N + 1];
        articulationPoints = new int[N + 1];
        visited = new boolean[N + 1];

        for (int i = 0; i < N + 1; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }

        Arrays.sort(articulationPoints, 1, N + 1);
        if (articulationPoints[0] == 0) {
            System.out.println("NONE");
        } else {
            for (int i = 1; i <= N; i++) {
                if (articulationPoints[i] == 1) {
                    System.out.print(articulationPoints[i] + " ");
                }
            }
        }
    }

    static int dfs(int node, int parent) {
        visited[node] = true;
        int children = 0;
        int low = disc[node];
        boolean isArticulation = false;

        for (int neighbour : graph.get(node)) {
            if (!visited[neighbour]) {
                children++;
                dfs(neighbour, node);
                low = Math.min(low, disc[neighbour]);
                if (low == disc[node] && node != parent) {
                    isArticulation = true;
                }
            } else if (neighbour != parent) {
                low = Math.min(low, disc[neighbour]);
            }
        }

        if (isArticulation) {
            articulationPoints[node] = 1;
        }

        return children;
    }
}
