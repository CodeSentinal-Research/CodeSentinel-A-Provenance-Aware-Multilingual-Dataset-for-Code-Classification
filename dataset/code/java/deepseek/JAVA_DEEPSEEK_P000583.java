import java.util.HashSet;
import java.util.Scanner;

public class Main {
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public static boolean hasCycle(ListNode head) {
        HashSet<ListNode> set = new HashSet<>();
        while (head != null) {
            if (set.contains(head)) {
                return true;
            }
            set.add(head);
            head = head.next;
       }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ListNode head = null;
        ListNode tail = null;
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            if (head == null) {
                head = new ListNode(val);
                tail = head;
            } else {
                tail.next = new ListNode(val);
                tail = tail.next;
            }
        }
        if (scanner.hasNext()) {
            int pos = scanner.nextInt();
            if (pos != -1) {
                ListNode cycleStart = head;
                for (int i = 0; i < pos; i++) {
                    cycleStart = cycleStart.next;
                }
                tail.next = cycleStart;
            }
        }
        System.out.println(hasCycle(head));
    }
}
