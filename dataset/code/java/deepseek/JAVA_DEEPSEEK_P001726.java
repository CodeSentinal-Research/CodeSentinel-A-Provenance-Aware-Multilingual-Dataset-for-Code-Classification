import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left, right;
        Node(int val) {
            this.val = val;
            left = right = null;
        }
    }

    static Node buildTree(String[] nodes) {
        Node root = new Node(Integer.parseInt(nodes[0]));
        Deque<Node> queue = new ArrayDeque<>();
        queue.offer(root);
        int i = 1;
        while (!queue.isEmpty() && i < nodes.length) {
            Node node = queue.poll();
            if (!nodes[i].equals("null")) {
                node.left = new Node(Integer.parseInt(nodes[i]));
                queue.offer(node.left);
            }
            i++;
            if (i < nodes.length && !nodes[i].equals("null")) {
                node.right = new Node(Integer.parseInt(nodes[i]));
                queue.offer(node.right);
            }
            i++;
        }
        return root;
    }

    static int countPaths(Node root, int sum) {
        if (root == null) return 0;
        int res = 0;
        if (sum == root.val) res++;
        res += countPaths(root.left, sum - root.val) + countPaths(root.right, sum - root.val);
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        String[] nodes = new String[n];
        nodes = br.readLine().split(" ");
        Node root = buildTree(nodes);
        int k = Integer.parseInt(br.readLine().trim());
        System.out.println(countPaths(root, k));
    }
}
