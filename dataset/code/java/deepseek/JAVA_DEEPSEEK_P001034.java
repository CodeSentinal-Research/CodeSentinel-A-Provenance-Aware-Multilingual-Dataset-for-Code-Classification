import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Comparator;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> queue = new PriorityQueue<>(Comparator.comparingInt(node -> node.val));
        for (ListNode list : lists) {
            if (list != null) {
                queue.offer(list);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        while (!queue.isEmpty()) {
            ListNode smallest = queue.poll();
            curr.next = smallest;
            curr = curr.next;
            if (smallest.next != null) {
                queue.offer(smallest.next);
            }
        }
        return dummy.next;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        ListNode[] lists = new ListNode[k];
        for (int i = 0; i < k; i++) {
            int n = scanner.nextInt();
            ListNode head = null;
            for (int j = 0; j < n; j++) {
                int val = scanner.nextInt();
                ListNode node = new ListNode(val);
                node.next = head;
                head = node;
            }
            lists[i] = head;
        }
        Solution solution = new Solution();
        ListNode result = solution.mergeKLists(lists);
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
