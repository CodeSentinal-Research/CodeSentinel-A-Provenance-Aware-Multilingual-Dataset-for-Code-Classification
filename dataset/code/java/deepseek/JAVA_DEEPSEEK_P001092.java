import java.util.*;
import java.io.*;

public class Main {
    static class Node {
        int id;
        List<Integer> children = new ArrayList<>();
    }

    static int Q, N, K;
    static Node[] nodes;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        Q = Integer.parseInt(line[1]);

        nodes = new Node[N + 1];
        visited = new boolean[N + 1];

        for (int i = 1; i < N; i++) {
            line = br.readLine().split(" ");
            int p = Integer.parseInt(line[0]);
            int c = Integer.parseInt(line[1]);
            nodes[p].children.add(c);
        }

        for (int i = 0; i < Q; i++) {
            line = br.readLine().split(" ");
            K = Integer.parseInt(line[1]);
            int node = Integer.parseInt(line[0]);
            out.println(findKthAncestor(node, K));
        }

        out.flush();
    }

    static int findKthAncestor(int node, int k) {
        visited[node] = true;
        if (k == 0) return node;
        if (nodes[node].children.isEmpty()) return -1;
        for (int child : nodes[node].children) {
            if (!visited[child]) {
                int res = findKthAncestor(child, k - 1);
                if (res != -1) return res;
            }
        }
        return -1;
    }
}
