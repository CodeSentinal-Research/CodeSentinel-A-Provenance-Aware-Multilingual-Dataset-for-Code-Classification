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

    static Node insert(Node root, int data) {
        if (root == null) {
            return new Node(data);
        } else {
            Node temp = null;
            if (data <= root.data) {
                temp = insert(root.left, data);
                root.left = temp;
            } else {
                temp = insert(root.right, data);
                root.right = temp;
           
               }
            return root;
        }
    }

    static Node search(Node root, int target) {
        if (root == null || root.data == target)
            return root;

        if (root.data > target)
            return search(root.left, target);

        return search(root.right, target);
    }

    static Node findPredecessor(Node root, int target) {
        Node targetNode = search(root, target);
        if (targetNode == null)
            return null;

        if (targetNode.left != null) {
            Node temp = targetNode.left;
            while (temp.right != null)
                temp = temp.right;
            return temp;
        }

        Node pred = null;
        Node current = root;
        while (current != targetNode) {
            if (current.data > target) {
                pred = current;
                current = current.left;
            } else {
                current = current.right;
            }
        }
        return pred;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        while (n-- > 0) {
            int data = sc.nextInt();
            root = insert(root, data);
        }
        int target = sc.nextInt();
        Node predecessor = findPredecessor(root, target);
        if (predecessor == null) {
            System.out.println("NONE");
        } else {
            System.out.println(predecessor.data);
        }
    }
}
