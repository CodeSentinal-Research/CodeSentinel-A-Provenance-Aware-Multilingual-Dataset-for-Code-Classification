import java.util.Scanner;

public class Main {
    static int cameras = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        Node root = null;
        for (int i = 0; i < n; i++) {
            String[] parts = scanner.nextLine().split(" ");
            int parent = Integer.parseInt(parts[0]);
            int child = Integer.parseInt(parts[1]);
            if (root == null) {
                root = new Node(parent);
                root.children.add(new Node(child));
            } else {
                Node parentNode = findNode(root, parent);
                if (parentNode != null) {
                    parentNode.children.add(new Node(child));
                }
            }
        }
        scanner.close();
        dfs(root);
        System.out.println(cameras);
    }

    public static Node findNode(Node root, int value) {
        if (root == null) {
            return null;
        }
        if (root.value == value) {
            return root;
        }
        for (Node child : root.children) {
            Node found = findNode(child, value);
            if (found != null) {
                return found;
            }
        }
        return null;
    }

    public static int dfs(Node node) {
        if (node == null) {
            return 2;
        }
        int res = 0;
        for (Node child : node.children) {
            res += dfs(child);
        }
        if (res == 0) {
            cameras++;
            return 1;
        }
        if (res == 1) {
            return 0;
        }
        if (res == 2) {
            return -1;
        }
        if (res == 3) {
            return 0;
        }
        if (res == 4) {
            return 2;
        }
        return 0;
    }

    static class Node {
        int value;
        Node parent;
        java.util.List<Node> children;

        Node(int value) {
            this.value = value;
            children = new java.util.ArrayList<>();
        }
    }
}
