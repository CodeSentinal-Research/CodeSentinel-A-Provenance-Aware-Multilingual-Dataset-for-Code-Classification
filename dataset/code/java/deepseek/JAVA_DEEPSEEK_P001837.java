import java.io.*;
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

    static class BSTIterator {
        Stack<Node> stack;

        public BSTIterator(Node root) {
            stack = new Stack<>();
            pushAll(root);
        }

        public boolean hasNext() {
            return !stack.isEmpty();
        }

        public int next() {
            Node node = stack.pop();
            pushAll(node.right);
            return node.val;
        }

        public boolean hasPrev() {
            return !stack.isEmpty();
        }

        public int prev() {
            Node node = stack.peek();
            pushAll(node.left);
            return node.val;
        }

        private void pushAll(Node node) {
            while (node != null) {
                stack.push(node);
                node = node.left;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Node root = null;
        for (int i = 0; i < n; i++) {
            String[] parts = br.readLine().split(" ");
            int val = Integer.parseInt(parts[0]);
            Node node = new Node(val);
            if (root == null) {
                root = node;
            } else {
                Node cur = root;
                while (true) {
                    if (val < cur.val) {
                        if (cur.left == null) {
                            cur.left = node;
                            break;
                        } else {
                            cur = cur.left;
                        }
                    } else {
                        if (cur.right == null) {
                            cur.right = node;
                            break;
                        } else {
                            cur = cur.right;
                        }
                    }
                }
            }
        }
        BSTIterator iterator = new BSTIterator(root);
        int q = Integer.parseInt(br.readLine());
        for (int i = 0; i < q; i++) {
            String op = br.readLine();
            if (op.equals("NEXT")) {
                if (iterator.hasNext()) {
                    System.out.println(iterator.next());
                } else {
                    System.out.println("NONE");
                }
            } else if (op.equals("PREV")) {
                if (iterator.hasPrev()) {
                    System.out.println(iterator.prev());
                } else {
                    System.out.println("NONE");
                }
            }
        }
    }
}
