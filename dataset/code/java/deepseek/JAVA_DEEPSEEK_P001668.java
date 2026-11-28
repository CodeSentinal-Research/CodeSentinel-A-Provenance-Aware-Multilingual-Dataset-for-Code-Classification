import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
            left = null;
            right = null;
        }
    }

    static class Info {
        Node node;
        int height;
        Info(Node node, int height) {
            this.node = node;
            this.height = height;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int left = scanner.nextInt();
            int right = scanner.nextInt();
            Node node = new Node(i + 1);
            if (left != -1) {
                node.left = nodes.get(left - 1);
            }
            if (right != -1) {
                node.right = nodes.get(right - 1);
            }
            nodes.add(node);
        }
        Info info = solve(nodes.get(0));
        System.out.println(info.node.val);
    }

    private static Info solve(Node node) {
        if (node == null) {
            return new Info(null, 0);
        }
        Info leftInfo = solve(node.left);
        Info rightInfo = solve(node.right);
        if (leftInfo.height > rightInfo.height + 1) {
            return new Info(node, leftInfo.height + 1);
        } else if (rightInfo.height > leftInfo.height + 1) {
            return new Info(node, rightInfo.height + 1);
        } else {
            return new Info(node, Math.max(leftInfo.height, rightInfo.height) + 1);
        }
    }
}
