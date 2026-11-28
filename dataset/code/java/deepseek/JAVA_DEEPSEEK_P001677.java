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
    static int target;

    static void inorder(Node node, int level, int parent, ArrayList<Integer> cousin) {
        if (node == null)
            return;
        if (level > 1 && parent != -1) {
            cousin.add(node.data);
        }
        inorder(node.left, level + 1, node.data, cousin);
        inorder(node.right, level + 1, node.data, cousin);
    }

    static ArrayList<Integer> cousins(Node node) {
        ArrayList<Integer> cousin = new ArrayList<>();
        inorder(node, 0, -1, cousin);
        if (cousin.size() == 1 && cousin.get(0) == target) {
            System.out.println("NONE");
            System.exit(0);
        }
        return cousin;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        root = new Node(1);
        for (int i = 1; i < n; i++) {
            int parent = sc.nextInt();
            char child = sc.next().charAt(0);
            if (child == 'L') {
                if (root.left == null) {
                    root.left = new Node(i + 1);
                } else {
                    Node temp = root.left;
                    while (temp.right != null) {
                        temp = temp.right;
                    }
                    temp.right = new Node(i + 1);
                }
            } else {
                if (root.right == null) {
                    root.right = new Node(i + 1);
                } else {
                    Node temp = root.right;
                    while (temp.left != null) {
                        temp = temp.left;
                    }
                    temp.left = new Node(i + 1);
                }
            }
        }
        target = sc.nextInt();
        ArrayList<Integer> res = cousins(root);
        for (int i = 0; i < res.size(); i++) {
            System.out.print(res.get(i) + " ");
        }
    }
}
