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

    static void inorder(Node root, ArrayList<Integer> arr) {
        if (root != null) {
            inorder(root.left, arr);
            arr.add(root.data);
            inorder(root.right, arr);
        }
    }

    static ArrayList<Integer> merge(ArrayList<Integer> a, ArrayList<Integer> b) {
        ArrayList<Integer> res = new ArrayList<>();
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a.get(i) < b.get(j)) {
                i++;
            } else if (b.get(j) < a.get(i)) {
                j++;
            } else {
                res.add(a.get(i));
                i++;
                j++;
            }
        }
        return res;
    }

    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        Node root1 = null;
        while (n1-- > 0) {
            int val = sc.nextInt();
            root1 = insert(root1, val);
        }
        int n2 = sc.nextInt();
        Node root2 = null;
        while (n2-- > 0) {
            int val = sc.nextInt();
            root2 = insert(root2, val);
        }
        ArrayList<Integer> arr1 = new ArrayList<>();
        ArrayList<Integer> arr2 = new ArrayList<>();
        inorder(root1, arr1);
        inorder(root2, arr2);
        ArrayList<Integer> res = merge(arr1, arr2);
        for (int val : res) {
            System.out.println(val);
        }
    }
}
