import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left, right;
        Node(int val) {
            this.val = val;
        }
    }

    static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] values = br.readLine().split(" ");
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(Integer.parseInt(values[i]));
        }
        for (int i = 0; i < n; i++) {
            String[] children = br.readLine().split(" ");
            if (!children[0].equals("-1")) {
                nodes[i].left = nodes[Integer.parseInt(children[0])];
            }
            if (!children[1].equals("-1")) {
                nodes[i].right = nodes[Integer.parseInt(children[1])];
           }
        }
        dfs(nodes[0], Integer.MIN_VALUE, Integer.MAX_VALUE);
        System.out.println(count);
    }

    static void dfs(Node node, int min, int max) {
        if (node == null) {
            return;
        }
        if (min < node.val && node.val < max) {
            count++;
        }
        dfs(node.left, Math.min(min, node.val), max);
        dfs(node.right, min, Math.max(max, node.val));
    }
}
