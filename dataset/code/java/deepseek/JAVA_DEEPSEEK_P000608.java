import java.util.Scanner;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public static boolean isSubPath(ListNode h, TreeNode r) {
        if (h == null) return true;
        if (r == null) return false;
        if (h.val == r.val && (isSubPath(h.next, r.left) || isSubPath(h.next, r.right)))
            return true;
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ListNode head = new ListNode(sc.nextInt());
        TreeNode root = new TreeNode(sc.nextInt());
        System.out.println(isSubPath(head, root));
    }
}
