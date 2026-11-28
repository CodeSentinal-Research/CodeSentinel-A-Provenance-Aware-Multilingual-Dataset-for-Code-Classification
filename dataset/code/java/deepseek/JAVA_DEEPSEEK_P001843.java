import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    Node(int d) {
        data = d;
        left = right = null;
    }
}

class LinkedList {
    Node head;
}

public class Main {
    static Scanner sc = new Scanner(System.in);

    Node sortedListToBST(LinkedList list, int n) {
        if (n <= 0)
            return null;

        Node left = sortedListToBST(list, n / 2);

        Node root = new Node(list.head.data);

        root.left = left;

        list.head = list.head.right;

        root.right = sortedListToBST(list, n - n / 2 - 1);

        return root;
    }

    Node push(Node node, int data) {
        Node temp = new Node(data);
        temp.left = node;
        return temp;
    }

    void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.right;
        }
    }

    public static void main(String[] args) {
        Main tree = new Main();
        int n = sc.nextInt();
        LinkedList list = new LinkedList();
        list.head = new Node(sc.nextInt());
        for (int i = 1; i < n; i++) {
            list.head = tree.push(list.head, sc.nextInt());
        }
        tree.printList(list.head);
        Node root = tree.sortedListToBST(list, n);
        System.out.print(root.data + " ");
    }
}
