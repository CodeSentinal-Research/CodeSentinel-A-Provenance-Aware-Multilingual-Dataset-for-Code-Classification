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

    public static void insert(Node node, int val) {
        if (val < node.val) {
            if (node.left != null) {
                insert(node.left, val);
            } else {
                node.left = new Node(val);
           }
        } else {
            if (node.right != null) {
                insert(node.right, val);
            } else {
                node.right = new Node(val);
            }
        }
    }

    public static Integer findMaxSmaller(Node node, int target) {
        if (node == null) {
            return null;
        }
        if (node.val >= target) {
            return findMaxSmaller(node.left, target);
        } else {
            Integer right = findMaxSmaller(node.right, target);
            return right != null ? right : node.val;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = new Node(scanner.nextInt());
        for (int i = 1; i < n; i++) {
            insert(root, scanner.nextInt());
        }
        int target = scanner.nextInt();
        Integer result = findMaxSmaller(root, target);
        System.out.println(result != null ? result : "NONE");
    }
}
