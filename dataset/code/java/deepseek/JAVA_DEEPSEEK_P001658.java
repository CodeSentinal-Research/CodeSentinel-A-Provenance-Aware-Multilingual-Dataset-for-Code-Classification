import java.util.*;
import java.io.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    static class Tree {
        Node root;
        Node target;
        int k;
        Tree(Node root, Node target, int k) {
            this.root = root;
            this.target = target;
            this.k = k;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 0; i < n - 1; i++) {
            String[] line = br.readLine().split(" ");
            int parent = Integer.parseInt(line[0]);
            int child = Integer.parseInt(line[1]);
            if (nodes[parent].left == null) {
                nodes[parent].left = nodes[child];
            } else {
                nodes[parent].right = nodes[child];
            }
        }
        String[] line = br.readLine().split(" ");
        int target = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);
        Tree tree = new Tree(nodes[0], nodes[target], k);
        List<Integer> res = new ArrayList<>();
        dfs(tree.root, tree.target, tree.k, res);
        for (int val : res) {
            System.out.println(val);
        }
    }

    static int dfs(Node node, Node target, int k, List<Integer> res) {
        if (node == null) {
            return -1;
        }
        if (node == target) {
            res.add(node.val);
            return 0;
        }
        int left = dfs(node.left, target, k, res);
        if (left != -1) {
            if (left + 1 == k) {
                res.add(node.val);
            } else {
                dfs(node.right, target, k - left - 1, res);
            }
            return left + 1;
        }
        int right = dfs(node.right, target, k, res);
        if (right != -1) {
            if (right + 1 == k) {
                res.add(node.val);
            } else {
                dfs(node.left, target, k - right - 1, res);
            }
            return right + 1;
        }
        return -1;
    }
}
