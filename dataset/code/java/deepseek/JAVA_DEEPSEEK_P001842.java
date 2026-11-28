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
            return new Node(data);
        }

        if (data < node.data) {
            node.left = insert(node.left, data);
        } else if (data > node.data) {
            node.right = insert(node.right, data);
        }

        return node;
    }

    static void inorder(Node root, ArrayList<Integer> arr) {
        if (root != null) {
            inorder(root.left, arr);
            arr.add(root.data);
            inorder(root.right, arr);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n1 = Integer.parseInt(br.readLine().trim());
        Node root1 = null;
        while (n1-- > 0) {
            int data = Integer.parseInt(br.readLine().trim());
            root1 = insert(root1, data);
        }

        int n2 = Integer.parseInt(br.readLine().trim());
        Node root2 = null;
        while (n2-- > 0) {
            int data = Integer.parseInt(br.readLine().trim());
            root2 = insert(root2, data);
        }

        ArrayList<Integer> arr1 = new ArrayList<>();
        inorder(root1, arr1);
        ArrayList<Integer> arr2 = new ArrayList<>();
        inorder(root2, arr2);

        int i = 0, j = 0;
        ArrayList<Integer> union = new ArrayList<>();
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1.get(i) < arr2.get(j)) {
                union.add(arr1.get(i++));
            } else if (arr2.get(j) < arr1.get(i)) {
                union.add(arr2.get(j++));
            } else {
                union.add(arr1.get(i));
                i++;
                j++;
            }
        }

        while (i < arr1.size()) {
            union.add(arr1.get(i++));
        }

        while (j < arr2.size()) {
            union.add(arr2.get(j++));
        }

        for (Integer num : union) {
            System.out.println(num);
        }
    }
}
