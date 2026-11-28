import java.util.Scanner;

public class Main {
    static class Node {
        Node left, right;
    }

    static int answer;

    static int solve(Node node) {
        if (node == null)
            return 0;

        int left = solve(node.left);
        int right = solve(node.right);

        if (left == right) {
            answer = Math.max(answer, left + right + 1);
            return Math.max(left, right) + 1;
        }

        return -1;
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
        answer = 0;
        solve(nodes[0]);
        System.out.println(answer);
    }
}
