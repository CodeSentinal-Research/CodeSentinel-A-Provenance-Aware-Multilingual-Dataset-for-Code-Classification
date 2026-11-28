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

    static void inorder(Node node, int level, List<Integer> res) {
        if (node != null) {
            inorder(node.left, level + 1, res);
            if (res.size() < level + 1) {
                res.add(node.data);
            } else if (res.get(level) < node.data) {
                res.set(level, node.data);
            }
            inorder(node.right, level + 1, res);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int data = sc.nextInt();
            if (i == 0) {
                root = new Node(data);
            } else {
                Node temp = root;
                Node parent = null;
                while (temp != null) {
                    parent = temp;
                    if (data < temp.data) {
                        temp = temp.left;
                    } else {
                        temp = temp.right;
                    }
                }
                if (data < parent.data) {
                    parent.left = new Node(data);
                } else {
                    parent.right = new Node(data);
                }
            }
        }
        List<Integer> res = new ArrayList<>();
        inorder(root, 0, res);
        for (int i = 0; i < res.size(); i++) {
            System.out.print(res.get(i) + " ");
        }
    }
}
