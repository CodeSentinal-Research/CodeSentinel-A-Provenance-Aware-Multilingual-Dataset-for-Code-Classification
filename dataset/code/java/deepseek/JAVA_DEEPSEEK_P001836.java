import java.io.*;
import java.util.*;

public class Main {
    public static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    public static class BSTIterator {
        Stack<Node> stack;

        public BSTIterator(Node root) {
            stack = new Stack<>();
            pushAll(root);
        }

        public boolean hasNext() {
            return !stack.isEmpty();
        }

        public int next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            Node node = stack.pop();
            pushAll(node.right);
            return node.val;
        }

        private void pushAll(Node node) {
            while (node != null) {
                stack.push(node);
                node = node.left;
            }
        }
    }

    public static Node insert(Node root, int val) {
        if (root == null) {
            return new Node(val);
        }
        if (val < root.val) {
            root.left = insert(root.left, val);
        } else if (val > root.val) {
            root.right = insert(root.right, val);
        }
        return root;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Node root = null;
        for (int i = 0; i < n; i++) {
            int val = Integer.parseInt(br.readLine());
            root = insert(root, val);
        }
        BSTIterator iterator = new BSTIterator(root);
        int q = Integer.parseInt(br.readLine());
        for (int i = 0; i < q; i++) {
            String operation = br.readLine();
            if (operation.equals("NEXT")) {
                if (iterator.hasNext()) {
                    System.out.println(iterator.next());
                } else {
                    System.out.println("null");
                }
            } else if (operation.equals("HASNEXT")) {
                System.out.println(iterator.hasNext());
            }
        }
    }
}
