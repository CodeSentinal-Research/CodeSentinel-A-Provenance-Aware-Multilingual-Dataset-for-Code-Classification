class ListNode {
    int val;
    ListNode prev, next;
    ListNode(int val) { this.val = val; }
}

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private ListNode cur;

    private int countNodes(ListNode node) {
        int count = 0;
        while (node != null) {
            count++;
            node = node.next;
        }
        return count;
    }

    private TreeNode build(int count) {
        if (count <= 0) return null;
        TreeNode left = build(count / 2);
        TreeNode root = new TreeNode(cur.val);
        cur = cur.next;
        root.left = left;
        root.right = build(count - count / 2 - 1);
        return root;
    }

    public TreeNode sortedListToBST(ListNode head) {
        int n = countNodes(head);
        cur = head;
        return build(n);
    }
}