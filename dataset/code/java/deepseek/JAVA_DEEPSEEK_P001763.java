import java.util.Scanner;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    static int count = 0;

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
        isUnivalue(nodes[0]);
        System.out.println(count);
    }

    static boolean isUnivalue(Node node) {
        if (node == null) {
            return true;
        }
        boolean isLeftUnivalue = isUnivalue(node.left);
        boolean isRightUnivalue = isUnivalue(node.right);
        if (!isLeftUnivalue || !isRightUnivalue) {
            return false;
        }
        if ((node.left != null && node.left.val != node.val) || (node.right != null && node.right.val != node.val)) {
            return false;
        }
        count++;
        return true;
    }
}
