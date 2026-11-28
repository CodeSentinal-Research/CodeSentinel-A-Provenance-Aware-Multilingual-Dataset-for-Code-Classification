import java.util.*;
import java.io.*;

public class Main {
    static class Node {
        int index;
        List<Node> children = new ArrayList<>();

        public Node(int index) {
            this.index = index;
        }
    }

    static List<List<Integer>> result = new ArrayList<>();
    static int[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line1 = br.readLine().split(" ");
        int V = Integer.parseInt(line1[0]);
        int E = Integer.parseInt(line1[1]);
        visited = new int[V];
        Node[] nodes = new Node[V];
        for (int i = 0; i < V; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 0; i < E; i++) {
            String[] edge = br.readLine().split(" ");
            int from = Integer.parseInt(edge[0]);
            int to = Integer.parseInt(edge[1]);
            nodes[from].children.add(nodes[to]);
        }
        List<Integer> path = new ArrayList<>();
        path.add(0);
        dfs(nodes[0], nodes, path);
        for (List<Integer> list : result) {
            for (int i : list) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    private static void dfs(Node node, Node[] nodes, List<Integer> path) {
        path.add(node.index);
        if (node.index == nodes.length - 1) {
            result.add(new ArrayList<>(path));
        } else {
            for (Node child : node.children) {
                dfs(child, nodes, path);
            }
        }
        path.remove(path.size() - 1);
    }
}
