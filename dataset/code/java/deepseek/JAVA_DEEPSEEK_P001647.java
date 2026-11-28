import java.util.*;
import java.io.*;

public class Main {
    static class Node {
        int data;
        Node left, right;

        public Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    static class Pair {
        Node node;
        int horizontal;

        public Pair(Node node, int horizontal) {
            this.node = node;
            this.horizontal = horizontal;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        Node root = new Node(Integer.parseInt(br.readLine()));
        Map<Integer, List<Node>> map = new HashMap<>();
        for (int i = 1; i < n; i++) {
            String[] s = br.readLine().split(" ");
            int parent = Integer.parseInt(s[0]);
            int left = Integer.parseInt(s[1]);
            int right = Integer.parseInt(s[2]);
            Node node = new Node(Integer.parseInt(s[3]));
            if (parent == -1) {
                root = node;
            } else {
                map.get(parent).add(node);
                if (left != -1) {
                    map.get(parent).get(0).left = new Node(left);
                }
                if (right != -1) {
                    map.get(parent).get(0).right = new Node(right);
                }
            }
        }

        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(root, 0));
        Map<Integer, Integer> bottomView = new TreeMap<>();
        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            bottomView.put(pair.horizontal, pair.node.data);
            if (pair.node.left != null) {
                queue.add(new Pair(pair.node.left, pair.horizontal - 1));
            }
            if (pair.node.right != null) {
                queue.add(new Pair(pair.node.right, pair.horizontal + 1));
            }
        }

        for (Map.Entry<Integer, Integer> entry : bottomView.entrySet()) {
            out.println(entry.getValue());
        }
        out.close();
    }
}
