import java.util.*;
import java.io.*;

public class Main {
    static class Node {
        int id;
        Node parent;
        List<Node> children = new ArrayList<>();

        Node(int id) {
            this.id = id;
        }

        Node(int id, Node parent) {
            this.id = id;
            this.parent = parent;
        }
    }

    static Node[] nodes;
    static int[] depth;

    static void dfs(Node node, int d) {
        depth[node.id] = d;
        for (Node child : node.children) {
            dfs(child, d + 1);
        }
    }

    static int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            return lca(v, u);
        }
        if (depth[u] == depth[v]) {
            return u;
        }
        return lca(nodes[u].parent.id, v);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        nodes = new Node[N + 1];
        depth = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            nodes[u].children.add(nodes[v]);
            nodes[v].parent = nodes[u];
        }
        dfs(nodes[1], 1);
        while (Q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            System.out.println(lca(u, v));
        }
    }
}
