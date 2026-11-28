import java.util.*;

public class Main {
    public static class Node {
        int data;
        Node left, right;
        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    public static void reverseLevelOrder(Node node) {
        Queue<Node> queue = new LinkedList<Node>();
        Stack<Node> stack = new Stack<Node>();
        queue.add(node);
        while (!queue.isEmpty()) {
            Node tempNode = queue.poll();
            stack.push(tempNode);

            if (tempNode.right != null) {
                queue.add(tempNode.right);
           }
            if (tempNode.left != null) {
                queue.add(tempNode.left);
            }
        }

        while (!stack.isEmpty()) {
            Node tempNode = stack.pop();
            System.out.print(tempNode.data + " ");
        }
    }

    public static void main(String args[]) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        reverseLevelOrder(root);
    }
}
