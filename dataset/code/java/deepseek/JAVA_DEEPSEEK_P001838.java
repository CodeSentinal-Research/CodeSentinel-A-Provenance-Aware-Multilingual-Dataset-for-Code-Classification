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

    public static boolean findPair(Node root, int sum, HashSet<Integer> set) {
        if (root == null) {
            return false;
        }

        if (findPair(root.left, sum, set)) {
            return true;
        }

        if (set.contains(sum - root.val)) {
            return true;
        } else {
            set.add(root.val);
        }

        return findPair(root.right, sum, set);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            Node node = new Node(val);
            if (root == null) {
                root = node;
            } else {
                Node current = root;
                while (true) {
                    if (val < current.val) {
                        if (current.left == null) {
                            current.left = node;
                            break;
                        } else {
                            current = current.left;
                        }
                    } else {
                        if (current.right == null) {
                            current.right = node;
                            break;
                        } else {
                            current = current.right;
                        }
                    }
                }
            }
        }
        int sum = scanner.nextInt();
        HashSet<Integer> set = new HashSet<>();
        if (findPair(root, sum, set)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
