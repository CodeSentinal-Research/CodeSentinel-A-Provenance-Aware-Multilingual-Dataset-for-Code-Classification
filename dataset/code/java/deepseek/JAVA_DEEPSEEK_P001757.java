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

    static Node buildTree(Scanner sc) {
        if (!sc.hasNext()) return null;
        String val = sc.next();
        if (val.equals("null")) return null;
        Node node = new Node(Integer.parseInt(val));
        node.left = buildTree(sc);
        node.right = buildTree(sc);
        return node;
   }

    static Node findNode(Node root, int target) {
        if (root == null) return null;
        if (root.val == target) return root;
        Node left = findNode(root.left, target);
        Node right = findNode(root.right, target);
        if (left != null) return left;
        return right;
    }

    static Node findNearestCommonAncestor(Node root, Node node1, Node node2) {
        if (root == null || root == node1 || root == node2) return root;
        Node left = findNearestCommonAncestor(root.left, node1, node2);
        Node right = findNearestCommonAncestor(root.right, node1, node2);
        if (left != null && right != null) return root;
        return left != null ? left : right;
    }

    static int findDistance(Node root, Node target, int distance) {
        if (root == null) return -1;
        if (root == target) return distance;
        int left = findDistance(root.left, target, distance + 1);
        int right = findDistance(root.right, target, distance + 1);
        return Math.max(left, right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node root = buildTree(sc);
        int node1Val = sc.nextInt();
        int node2Val = sc.nextInt();
        Node node1 = findNode(root, node1Val);
        Node node2 = findNode(root, node2Val);
        Node ancestor = findNearestCommonAncestor(root, node1, node2);
        int distance1 = findDistance(ancestor, node1, 0);
        int distance2 = findDistance(ancestor, node2, 0);
        System.out.println(distance1 + distance2);
    }
}
