import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
            left = null;
            right = null;
        }
    }

    static Node buildTree(Scanner sc) {
        if (!sc.hasNext()) return null;
        String val = sc.next();
        if (val.equals("null")) return null;
        Node node = new Node(Integer.parseInt(val));
        node.left = buildTree(sc);
        node.right = buildTree(sc);
        return node;
   }

    static boolean isIdentical(Node node1, Node node2) {
        if (node1 == null && node2 == null) return true;
        if (node1 == null || node2 == null) return false;
        return (node1.val == node2.val && isIdentical(node1.left, node2.left) && isIdentical(node1.right, node2.right));
    }

    static Node mirror(Node node) {
        if (node == null) return null;
        Node left = mirror(node.left);
        Node right = mirror(node.right);
        node.left = right;
        node.right = left;
        return node;
    }

    static boolean isSubtree(Node T, Node S) {
        if (S == null) return true;
        if (T == null) return false;
        if (isIdentical(T, S)) return true;
        return isSubtree(T.left, S) || isSubtree(T.right, S);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node T = buildTree(sc);
        Node S = mirror(T);
        if (isSubtree(T, S)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
