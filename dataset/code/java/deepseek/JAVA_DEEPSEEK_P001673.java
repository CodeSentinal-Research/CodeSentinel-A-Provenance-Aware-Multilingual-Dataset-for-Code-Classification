import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;
import java.util.TreeSet;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    static class BinaryTree {
        Node root;

        Node buildTreeUtil(LinkedList<Integer> list, int min, int max) {
            if (list.isEmpty()) return null;

            Node root = new Node(list.get(0));

            LinkedList<Integer> leftList = new LinkedList<>();
            LinkedList<Integer> rightList = new LinkedList<>();

            for (Integer i : list) {
                if (i > min && i < max) {
                    if (i < list.get(0)) leftList.add(i);
                    else rightList.add(i);
                }
            }

            root.left = buildTreeUtil(leftList, min, root.data);
            root.right = buildTreeUtil(rightList, root.data, max);

            return root;
        }

        void leftView(Node node) {
            if (node == null) return;

            System.out.print(node.data + " ");

            if (node.left != null)
                leftView(node.left);
            else
                leftView(node.right);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        LinkedList<Integer> list = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }

        BinaryTree tree = new BinaryTree();
        tree.root = tree.buildTreeUtil(list, Integer.MIN_VALUE, Integer.MAX_VALUE);
        tree.leftView(tree.root);
    }
}
