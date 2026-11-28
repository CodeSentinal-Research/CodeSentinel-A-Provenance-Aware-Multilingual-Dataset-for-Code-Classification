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

    static void inorder(Node node, int level, int[] max_level, int[] res) {
        if (node == null)
            return;

        inorder(node.left, level + 1, max_level, res);

        if (max_level[0] < level) {
            res[0] = node.data;
            max_level[0] = level;
        }

        inorder(node.right, level + 1, max_level, res);
    }

    static int findLeftMostLeaf(Node node) {
        if (node == null)
            return -1;

        int res = node.data, max_level[] = new int[1], level = 0;
        inorder(node, level, max_level, new int[1]);

        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        root = null;
        for (int i = 0; i < n; i++) {
            int data = sc.nextInt();
            String left = sc.next();
            String right = sc.next();
            Node new_node = new Node(data);
            if (left.equals("null"))
                new_node.left = null;
            else
                new_node.left = new Node(Integer.parseInt(left));
            if (right.equals("null"))
                new_node.right = null;
            else
                new_node.right = new Node(Integer.parseInt(right));
            root = new_node;
        }
        System.out.println(findLeftMostLeaf(root));
    }
}
