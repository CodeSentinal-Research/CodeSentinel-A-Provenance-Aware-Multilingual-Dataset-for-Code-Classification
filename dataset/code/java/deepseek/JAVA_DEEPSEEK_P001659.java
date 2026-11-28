import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Node {
    int data;
    Node left, right, next;

    Node(int data) {
        this.data = data;
        left = right = next = null;
    }
}

public class Main {
    public static void connect(Node root) {
        if (root == null) return;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            Node cur = queue.poll(), prev = null;
            if (cur != null) {
                prev = cur;
                while (cur != null) {
                    Node next = cur.left != null ? cur.left : cur.right;
                    if (prev.next != null) {
                        prev.next.next = next;
                        prev = prev.next;
                    } else {
                        prev.next = next;
                        prev = prev.next;
                    }
                    cur = cur.right;
                }
                queue.offer(null);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node(sc.nextInt());
            if (i > 1) {
                nodes[sc.nextInt()].left = nodes[i];
                nodes[sc.nextInt()].right = nodes[i];
            }
        }
        connect(nodes[1]);
        for (int i = 1; i <= n; i++) {
            if (nodes[i].left != null && nodes[i].right != null) {
                System.out.print(nodes[i].left.data + " " + nodes[i].right.data + " ");
            } else {
                System.out.print(nodes[i].left != null ? nodes[i].left.data : -1 + " " + nodes[i].right.data + " ");
            }
        }
    }
}
