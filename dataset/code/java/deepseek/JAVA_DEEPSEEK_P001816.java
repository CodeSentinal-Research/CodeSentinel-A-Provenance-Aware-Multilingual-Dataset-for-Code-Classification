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

    static int findFloor(Node root, int input) {
        if(root == null)
            return Integer.MAX_VALUE;

        if(root.data == input)
            return root.data;

        if(root.data > input)
            return findFloor(root.left, input);

        int floor = findFloor(root.right, input);
        return (floor <= input) ? floor : root.data;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        while (n-- > 0) {
            int val = sc.nextInt();
            root = insert(root, val);
        }
        int input = sc.nextInt();
        int floor = findFloor(root, input);
        if(floor == Integer.MAX_VALUE)
            System.out.println("NONE");
        else
            System.out.println(floor);
    }
}
