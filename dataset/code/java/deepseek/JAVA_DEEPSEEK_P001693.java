import java.util.Scanner;

public class Main {
    static int max = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(scanner.nextInt());
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
        longestUnivaluePath(nodes[0]);
        System.out.println(max);
    }

    static int longestUnivaluePath(Node node) {
        if (node == null) return 0;
        int left = longestUnivaluePath(node.left);
        int right = longestUnivaluePath(node.right);
        if (node.left != null && node.left.val == node.val) left++;
        else left = 0;
        if (node.right != null && node.right.val == node.val) right++;
        else right = 0;
        max = Math.max(max, left + right);
        return Math.max(left, right);
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
