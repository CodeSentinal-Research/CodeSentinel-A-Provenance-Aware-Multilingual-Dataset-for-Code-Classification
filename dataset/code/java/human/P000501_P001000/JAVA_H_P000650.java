
//13. Get nth node from begining of LinkedList
import java.util.Scanner;

class Node {
    int data;
    Node next;

    public Node(int x) {
        data = x;
        next = null;
    }
}

class NthNodeFromBeginning {
    Node head = null;
    public void insertLast(int x) {
        Node newNode = new Node(x);
        if (head == null) {
            head = newNode;
        } else {
            Node cur = head;
            while (cur.next != null) {
                cur = cur.next;
            }
            cur.next = newNode;
        }
    }
    public int getNthFromBeginning(int n) {
        Node cur = head;
        int count = 1; 

        while (cur != null) {
            if (count == n) {
                return cur.data;
            }
            cur = cur.next;
            count++;
        }

        // If n is greater than the number of nodes
        System.out.println("Invalid value of n. List has fewer than " + n + " nodes.");
        return -1;
    }

    // Function to display linked list
    public void display() {
        Node cur = head;
        while (cur != null) {
            System.out.print(cur.data + " -> ");
            cur = cur.next;
        }
        System.out.println("NULL");
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        NthNodeFromBeginning list = new NthNodeFromBeginning();

        System.out.println("Enter number of nodes: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.println("Enter data for node " + (i + 1) + " : ");
            int a = sc.nextInt();
            list.insertLast(a);
        }

        System.out.println("\nLinked List:");
        list.display();

        System.out.println("\nEnter value of n to find nth node from beginning: ");
        int nth = sc.nextInt();

        int result = list.getNthFromBeginning(nth);
        if (result != -1) {
            System.out.println("The " + nth + "th node from the beginning is: " + result);
        }

        sc.close();
    }
}
