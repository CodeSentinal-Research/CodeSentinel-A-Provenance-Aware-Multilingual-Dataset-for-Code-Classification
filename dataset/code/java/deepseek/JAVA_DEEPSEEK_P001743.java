import java.util.*;

public class Main {
    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
            left = null;
            right = null;
        }
    }

    static class Pair {
        Node node;
        int level;

        Pair(Node node, int level) {
            this.node = node;
            this.level = level;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i+1);
        }
        for (int i = 0; i < n; i++) {
            int left = scanner.nextInt() - 1;
            int right = scanner.nextInt() - 1;
            if (left != -1) {
                nodes[i].left = nodes[left];
            }
            if (right != -1) {
                nodes[i].right = nodes[right];
            }
        }
        Node root = nodes[0];
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(root, 0));
        int minLevel = Integer.MAX_VALUE;
        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            Node node = pair.node;
            int level = pair.level;
            if (node.left == null && node.right != null || node.left != null && node.right == null) {
                minLevel = Math.min(minLevel, level);
            }
            if (node.left != null) {
                queue.offer(new Pair(node.left, level+1));
            }
            if (node.right != null) {
                queue.offer(new Pair(node.right, level+1));
            }
        }
        if (minLevel == Integer.MAX_VALUE) {
            System.out.println("NONE");
        } else {
            System.out.println(minLevel);
        }
    }
}
