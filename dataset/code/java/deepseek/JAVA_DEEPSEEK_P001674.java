import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    static class BinaryTree {
        Node root;

        Node construct(int[] arr, int[] index, int min, int max) {
            if (index[0] > arr.length) {
                return null;
            }

            if (index[0] < min || index[0] > max) {
                index[0]++;
                return null;
            }

            Node node = new Node(arr[index[0]]);
            index[0]++;

            node.left = construct(arr, index, min, node.data);
            node.right = construct(arr, index, node.data + 1, max);

            return node;
        }

        void rightView(Node node) {
            if (node == null) {
                return;
            }

            System.out.print(node.data + " ");
            rightView(node.right);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();

        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }

        BinaryTree binaryTree = new BinaryTree();
        binaryTree.root = binaryTree.construct(arr, new int[]{0}, 0, Integer.MAX_VALUE);
        binaryTree.rightView(binaryTree.root);
    }
}
