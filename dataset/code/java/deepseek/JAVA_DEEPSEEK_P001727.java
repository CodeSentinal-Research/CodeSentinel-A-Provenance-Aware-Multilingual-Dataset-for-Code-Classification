import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left, right;
        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    static Node root;

    static void printPaths(Node node, ArrayList<Integer> path) {
        if (node == null)
            return;

        path.add(node.data);

        if (node.left == null && node.right == null) {
            for (int i = 0; i < path.size(); i++) {
                System.out.println(path.get(i) + " ");
            }
            System.out.println();
        }

        printPaths(node.left, path);
        printPaths(node.right, path);

        path.remove(path.size() - 1);
    }

    public static void main(String[] args) {
        root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        ArrayList<Integer> path = new ArrayList<>();
        printPaths(root, path);
    }
}
