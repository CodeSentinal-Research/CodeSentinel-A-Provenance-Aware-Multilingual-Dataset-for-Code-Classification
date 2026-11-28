import java.io.*;
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

    public static Node buildTree(BufferedReader br) throws IOException {
        String nodeStr = br.readLine();
        if (nodeStr.equals("null")) {
            return null;
        }
        Node node = new Node(Integer.parseInt(nodeStr));
        node.left = buildTree(br);
        node.right = buildTree(br);
        return node;
    }

    public static boolean isIdentical(Node node1, Node node2) {
        if (node1 == null && node2 == null) {
            return true;
        }
        if (node1 == null || node2 == null) {
            return false;
        }
        return (node1.val == node2.val) && isIdentical(node1.left, node2.left) && isIdentical(node1.right, node2.right);
    }

    public static boolean isSubtree(Node tree, Node subTree) {
        if (subTree == null) {
            return true;
        }
        if (tree == null) {
            return false;
        }
        if (isIdentical(tree, subTree)) {
            return true;
        }
        return isSubtree(tree.left, subTree) || isSubtree(tree.right, subTree);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Node tree = buildTree(br);
        Node subTree = buildTree(br);
        System.out.println(isSubtree(tree, subTree) ? "YES" : "NO");
    }
}
