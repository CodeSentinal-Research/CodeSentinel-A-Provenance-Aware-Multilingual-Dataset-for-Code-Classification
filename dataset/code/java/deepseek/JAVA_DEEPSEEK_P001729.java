import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    static Node root;

    static void createTree(int[] nodes) {
        Map<Integer, Node> nodeMap = new HashMap<>();
        for (int i = 0; i < nodes.length; i++) {
            nodeMap.put(i, new Node(i));
        }
        for (int i = 0; i < nodes.length; i++) {
            if (nodes[i] != -1) {
                if (nodeMap.get(i).left == null) {
                    nodeMap.get(i).left = nodeMap.get(nodes[i]);
                } else {
                    nodeMap.get(i).right = nodeMap.get(nodes[i]);
               }
            } else {
                root = nodeMap.get(i);
            }
        }
    }

    static int distance(Node root, int a, int b, int[] lca) {
        if (root == null) {
            return 0;
        }
        if (root.val == a || root.val == b) {
            return 1;
        }
        int left = distance(root.left, a, b, lca);
        int right = distance(root.right, a, b, lca);
        if (left > 0 && right > 0) {
            lca[0] = root.val;
            return 0;
        }
        return left > 0 ? left + 1 : right + 1;
    }

    static int lcaDistance(Node root, int a, int b) {
        int[] lca = new int[1];
        distance(root, a, b, lca);
        int lcaNode = lca[0];
        return distance(root, a, lcaNode, new int[1]) + distance(root, b, lcaNode, new int[1]) - 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nodes = new int[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = sc.nextInt();
        }
        int a = sc.nextInt();
        int b = sc.nextInt();
        createTree(nodes);
        System.out.println(lcaDistance(root, a, b));
    }
}
