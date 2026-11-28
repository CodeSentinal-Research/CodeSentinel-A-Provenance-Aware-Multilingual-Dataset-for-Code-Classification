import java.util.Scanner;

public class Main {
    public static class Node {
        Node left;
        Node right;
    }

    public static int countFullNodes(Node root) {
        if (root == null) {
            return 0;
        }
        int count = 0;
        if (root.left != null && root.right != null) {
            count = 1;
        }
        return count + countFullNodes(root.left) + countFullNodes(root.right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < n; i++) {
            int leftIndex = scanner.nextInt();
            int rightIndex = scanner.nextInt();
            if (leftIndex != -1) {
                nodes[i].left = nodes[leftIndex];
            }
            if (rightIndex != -1) {
                nodes[i].right = nodes[rightIndex];
            }
        }
        System.out.println(countFullNodes(nodes[0]));
    }
}
