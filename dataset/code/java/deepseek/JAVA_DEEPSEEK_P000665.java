import java.io.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        ListNode head = stringToListNode(in.readLine());
        ListNode ret = new Solution().reverse(head);
        out.println(listNodeToString(ret));
        out.close();
    }

    static ListNode stringToListNode(String input) {
        // Generate list from the input
        String[] parts = input.split(",");
        String item = parts[0];
        ListNode head = new ListNode(Integer.parseInt(item));
        ListNode point = head;
        for (int i = 1; i < parts.length; i++) {
            item = parts[i];
            point.next = new ListNode(Integer.parseInt(item));
            point = point.next;
        }
        point.next = head; // Make it circular
        return head;
    }

    static String listNodeToString(ListNode node) {
        if (node == null) {
            return "[]";
        }

        StringBuilder result = new StringBuilder();
        result.append(node.val);

        ListNode cursor = node.next;
        while (cursor != node) {
            result.append(",").append(cursor.val);
            cursor = cursor.next;
        }

        return result.toString();
    }
}

class Solution {
    public ListNode reverse(ListNode head) {
        if (head == null || head.next == head) {
            return head;
        }

        ListNode prev = null;
        ListNode curr = head;
        ListNode next = null;

        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
}
