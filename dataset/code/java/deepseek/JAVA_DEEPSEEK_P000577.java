import java.util.*;

public class Main {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public List<Integer> bottomView(TreeNode root) {
        if(root == null) return new ArrayList<>();
        Map<Integer, Integer> map = new TreeMap<>();
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(root, 0));
        while(!queue.isEmpty()){
            Pair p = queue.poll();
            map.put(p.hd, p.node.val);
            if(p.node.left != null) {
                queue.add(new Pair(p.node.left, p.hd-1));
            }
            if(p.node.right != null) {
                queue.add(new Pair(p.node.right, p.hd+1));
           }
        }
        return new ArrayList<>(map.values());
    }

    public static class Pair {
        TreeNode node;
        int hd;
        Pair(TreeNode node, int hd) {
            this.node = node;
            this.hd = hd;
        }
    }
}
