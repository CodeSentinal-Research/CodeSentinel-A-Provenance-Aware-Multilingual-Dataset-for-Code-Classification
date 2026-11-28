import java.util.Scanner;

public class Main {
    public static class Node {
        int val;
        Node next;
        Node(int x) {
            val = x;
            next = null;
        }
    }

    public static Node[] splitList(Node head) {
        Node slow = head, fast = head, prev = null;
        while(fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        prev.next = null;
        Node head2 = slow;
        slow = slow.next;
        head2.next = null;
        while(slow != null) {
            Node temp = slow.next;
            slow.next = head2;
            head2 = slow;
            slow = temp;
        }
        return new Node[]{head, head2};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node head = null, tail = null;
        for(int i = 0; i < n; i++) {
            int val = sc.nextInt();
            if(head == null) {
                head = new Node(val);
                tail = head;
            } else {
                tail.next = new Node(val);
                tail = tail.next;
            }
        }
        tail.next = head;
        Node[] result = splitList(head);
        System.out.println(result[0].val + " " + result[1].val);
    }
}
