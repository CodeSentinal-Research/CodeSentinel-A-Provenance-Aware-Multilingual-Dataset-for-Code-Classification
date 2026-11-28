import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            if (root == null) {
                root = new Node(val);
            } else {
                insertNode(root, val);
           }
        }
        System.out.println(isSameLevel(root) ? "YES" : "NO");
    }

    private static void insertNode(Node node, int val) {
        if (val < node.val) {
            if (node.left == null) {
                node.left = new Node(val);
            } else {
                insertNode(node.left, val);
            }
        } else {
            if (node.right == null) {
                node.right = new Node(val);
            } else {
                insertNode(node.right, val);
            }
        }
    }

    private static boolean isSameLevel(Node node) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(node);
        int level = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node curr = queue.poll();
                if (curr.left == null && curr.right == null) {
                    if (level != 0 && level != i) {
                        return false;
                    }
                    level = i;
                }
                if (curr.left != null) {
                    queue.offer(curr.left);
                }
                if (curr.right != null) {
                    queue.offer(curr.right);
                }
            }
        }
        return true;
    }

    static class Node {
        int val;
        Node left;
        Node right;

        Node(int val) {
            this.val = val;
        }
    }
}
