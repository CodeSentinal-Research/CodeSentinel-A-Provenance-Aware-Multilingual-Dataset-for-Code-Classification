import java.io.*;
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

    static Node insert(Node node, int data) {
        if (node == null) {
            return (new Node(data));
        } else {
            if (data <= node.data) {
                node.left = insert(node.left, data);
            } else {
                node.right = insert(node.right, data);
            }
            return node;
        }
    }

    static boolean findPair(Node node1, Node node2, int sum, HashSet<Integer> set) {
        if (node1 == null || node2 == null) {
            return false;
        }

        if (findPair(node1.left, node2, sum, set) || findPair(node1.right, node2, sum, set)) {
            return true;
        }

        if (set.contains(sum - node2.data - node1.data)) {
            return true;
        }

        set.add(node1.data + node2.data);
        return findPair(node1.left, node2.right, sum, set);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        Node root1 = null;
        while (n1-- > 0) {
            root1 = insert(root1, sc.nextInt());
        }

        int n2 = sc.nextInt();
        Node root2 = null;
        while (n2-- > 0) {
            root2 = insert(root2, sc.nextInt());
        }

        int sum = sc.nextInt();
        HashSet<Integer> set = new HashSet<>();
        if (findPair(root1, root2, sum, set)) {
            System.out.println(set.size());
        } else {
            System.out.println(0);
        }
    }
}
