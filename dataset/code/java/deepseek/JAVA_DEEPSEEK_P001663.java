import java.util.Scanner;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    static class Tree {
        Node root;

        void create(int[] arr, int start, int end, int i) {
            if (start > end) {
                return;
            }
            int mid = (start + end) / 2;
            root = new Node(arr[mid]);
            create(arr, start, mid - 1, 2 * i + 1);
            create(arr, mid + 1, end, 2 * i + 2);
        }

        boolean isComplete() {
            int totalNodes = 0;
            int totalNonLeafNodes = 0;
            int height = 0;
            int i = 0;
            Node node = root;
            while (node != null) {
                totalNodes++;
                if (node.left != null || node.right != null) {
                    totalNonLeafNodes++;
                }
                height = Math.max(height, totalNonLeafNodes);
                node = node.left;
                if (node == null) {
                    node = node.right;
                    i++;
                }
            }
            return totalNodes == Math.pow(2, height) - 1 && totalNonLeafNodes == height;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        Tree tree = new Tree();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        tree.create(arr, 0, n - 1, 0);
        System.out.println(tree.isComplete() ? "YES" : "NO");
    }
}
