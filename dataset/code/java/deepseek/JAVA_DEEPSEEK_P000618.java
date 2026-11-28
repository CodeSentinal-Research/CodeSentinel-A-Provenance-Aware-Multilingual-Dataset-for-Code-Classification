import java.util.HashMap;
import java.util.Map;

public class Main {
    public static Node copyRandomList(Node head) {
        if(head == null) return null;
        Map<Node, Node> map = new HashMap<>();
        Node current = head;
        while(current != null) {
            map.put(current, new Node(current.val));
            current = current.next;
        }
        current = head;
        while(current != null) {
            map.get(current).next = map.get(current.next);
            map.get(current).random = map.get(current.random);
            current = current.next;
       }
        return map.get(head);
    }

    public static void main(String[] args) {
        Node node1 = new Node(1);
        Node node2 = new Node(2);
        node1.next = node2;
        node1.random = node2;
        Node copy = copyRandomList(node1);
        System.out.println(copy.val);
        System.out.println(copy.next.val);
        System.out.println(copy.random.val);
    }
}

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
