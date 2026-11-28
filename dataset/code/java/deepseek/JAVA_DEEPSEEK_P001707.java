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

    static Node root;

    static void insert(int value) {
        root = insertRec(root, value);
    }

    static Node insertRec(Node root, int value) {
        if (root == null) {
            root = new Node(value);
            return root;
        }

        if (value < root.val)
            root.left = insertRec(root.left, value);
        else if (value > root.val)
            root.right = insertRec(root.right, value);

        return root;
    }

    static void insertLevel(int value, int depth) {
        Queue<Node> q = new LinkedList<>();
        q.add(root);

        for (int i = 1; i < depth; i++) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                Node temp = q.poll();
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
        }

        while (!q.isEmpty()) {
            Node temp = q.poll();
            temp.left = new Node(value);
            temp.right = new Node(value);
        }
    }

    static void inOrder(Node node) {
        if (node == null)
            return;

        inOrder(node.left);
        System.out.print(node.val + " ");
        inOrder(node.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n-- > 0) {
            insert(sc.nextInt());
        }
        int value = sc.nextInt();
        int depth = sc.nextInt();
        insertLevel(value, depth);
        inOrder(root);
    }
}
