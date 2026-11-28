import java.util.Scanner;

public class Main {
    static class Node {
        Node left, right;
    }

    static int countPaths(Node root) {
        if (root == null)
            return 0;
        if (root.left == null && root.right == null)
            return 1;
        return countPaths(root.left) + countPaths(root.right);
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
        System.out.println(countPaths(nodes[0]));
    }
}
