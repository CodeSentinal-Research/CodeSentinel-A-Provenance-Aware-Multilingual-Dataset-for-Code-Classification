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
        Node[] nodeList = new Node[nodes.length];
        for (int i = 0; i < nodes.length; i++) {
            nodeList[i] = new Node(Integer.parseInt(nodes[i]));
        }
        for (int i = 0; i*2+2 < nodes.length; i++) {
            nodeList[i].left = nodeList[i*2+1];
            nodeList[i].right = nodeList[i*2+2];
       }
        return nodeList[0];
    }

    static boolean isEvenOddTree(Node root) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        int level = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            int prev = level % 2 == 0 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            for (int i = 0; i < size; i++) {
                Node node = queue.poll();
                if (level % 2 == 0) {
                    if (node.val <= prev || node.val % 2 == 0) return false;
                } else {
                    if (node.val >= prev || node.val % 2 != 0) return false;
                }
                prev = node.val;
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
            level++;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String[] nodes = new String[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = scanner.nextLine();
        }
        Node root = buildTree(nodes);
        System.out.println(isEvenOddTree(root) ? "YES" : "NO");
    }
}
