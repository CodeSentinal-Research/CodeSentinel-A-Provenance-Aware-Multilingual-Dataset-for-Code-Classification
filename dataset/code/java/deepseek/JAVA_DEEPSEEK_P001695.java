import java.util.*;

public class Main {
    public static class Node {
        Node left, right;
    }

    public static int sum = 0;

    public static void dfs(Node node, int num) {
        if (node != null) {
            num = (num << 1) | (node.left != null ? 1 : 0);
            if (node.right == null && node.left == null) {
                sum += num;
            } else {
                dfs(node.left, num);
                dfs(node.right, num);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < n; i++) {
            int left = scanner.nextInt();
            int right = scanner.nextInt();
            if (left != -1) {
                nodes[i].left = nodes[left - 1];
            }
            if (right != -1) {
                nodes[i].right = nodes[right - 1];
            }
        }
        dfs(nodes[0], 0);
        System.out.println(sum);
    }
}
