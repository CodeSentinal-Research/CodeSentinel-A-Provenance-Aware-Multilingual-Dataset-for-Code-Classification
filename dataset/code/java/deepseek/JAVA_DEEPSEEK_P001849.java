import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] keys = new int[n];
        for (int i = 0; i < n; i++) {
            keys[i] = scanner.nextInt();
        }
        System.out.println(findHeight(keys));
    }

    private static int findHeight(int[] keys) {
        int height = 0;
        for (int key : keys) {
            height = Math.max(height, insertAndGetHeight(key));
        }
        return height;
    }

    private static int insertAndGetHeight(int key) {
        if (root == null) {
            root = new Node(key);
            return 0;
        }
        Node current = root;
        int height = 0;
        while (true) {
            height++;
            if (key < current.key) {
                if (current.left == null) {
                    current.left = new Node(key);
                    return height;
                }
                current = current.left;
            } else {
                if (current.right == null) {
                    current.right = new Node(key);
                    return height;
                }
                current = current.right;
            }
        }
    }

    static class Node {
        int key;
        Node left, right;

        Node(int key) {
            this.key = key;
        }
    }

    static Node root;
}
