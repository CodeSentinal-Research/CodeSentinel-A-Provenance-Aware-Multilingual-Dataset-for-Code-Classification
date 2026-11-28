import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    static class Pair {
        Node node;
        int col;
        Pair(Node node, int col) {
            this.node = node;
            this.col = col;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(sc.nextInt());
        }
        for (int i = 0; i < n; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n) {
                nodes[i].left = nodes[left];
            }
            if (right < n) {
                nodes[i].right = nodes[right];
            }
        }
        verticalSum(nodes[0]);
    }

    public static void verticalSum(Node root) {
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(root, 0));
        TreeMap<Integer, Integer> map = new TreeMap<>();
        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            Node node = pair.node;
            int col = pair.col;
            map.put(col, map.getOrDefault(col, 0) + node.val);
            if (node.left != null) {
                queue.offer(new Pair(node.left, col - 1));
            }
            if (node.right != null) {
                queue.offer(new Pair(node.right, col + 1));
            }
        }
        for (int sum : map.values()) {
            System.out.print(sum + " ");
        }
    }
}
