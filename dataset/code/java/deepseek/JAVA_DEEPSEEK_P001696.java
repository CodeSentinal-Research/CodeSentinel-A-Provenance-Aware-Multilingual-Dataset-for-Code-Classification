import java.util.*;

public class Main {
    static class Node {
        char val;
        Node left;
        Node right;
        Node(char val) {
            this.val = val;
        }
    }

    static String smallest = "~";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        char[] letters = sc.nextLine().toCharArray();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(letters[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            if (nodes[a].left == null) {
                nodes[a].left = nodes[b];
            } else {
                nodes[a].right = nodes[b];
            }
        }
        dfs(nodes[0], "");
        System.out.println(smallest);
    }

    static void dfs(Node node, String s) {
        if (node == null) {
            return;
        }
        s = node.val + s;
        if (node.left == null && node.right == null) {
            if (s.compareTo(smallest) < 0) {
                smallest = s;
            }
        } else {
            dfs(node.left, s);
            dfs(node.right, s);
        }
    }
}
