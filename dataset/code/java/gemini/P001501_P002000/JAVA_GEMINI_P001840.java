class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Codec {
    private void preorder(TreeNode node, StringBuilder sb) {
        if (node == null) return;
        sb.append(node.val).append(" ");
        preorder(node.left, sb);
        preorder(node.right, sb);
    }

    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        preorder(root, sb);
        return sb.toString().trim();
    }

    private int idx = 0;

    private TreeNode build(String[] tokens, int bound) {
        if (idx == tokens.length || Integer.parseInt(tokens[idx]) > bound) return null;
        int val = Integer.parseInt(tokens[idx++]);
        TreeNode node = new TreeNode(val);
        node.left = build(tokens, val);
        node.right = build(tokens, bound);
        return node;
    }

    public TreeNode deserialize(String data) {
        if (data == null || data.isEmpty()) return null;
        String[] tokens = data.split("\\s+");
        idx = 0;
        return build(tokens, Integer.MAX_VALUE);
    }
}