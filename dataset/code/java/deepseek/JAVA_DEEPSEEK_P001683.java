import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left, right;
        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    static class Pair {
        Node node;
        boolean isLeft;
        Pair(Node node, boolean isLeft) {
            this.node = node;
            this.isLeft = isLeft;
        }
    }

    static Node buildTree(String[] nodes) {
        if(nodes[0].equals("null")) return null;
        Node root = new Node(Integer.parseInt(nodes[0]));
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, false));
        int i = 1;
        while(!q.isEmpty() && i < nodes.length) {
            Pair p = q.poll();
            if(!nodes[i].equals("null")) {
                Node left = new Node(Integer.parseInt(nodes[i]));
                p.node.left = left;
                q.add(new Pair(left, true));
            }
            i++;
            if(i < nodes.length && !nodes[i].equals("null")) {
                Node right = new Node(Integer.parseInt(nodes[i]));
                p.node.right = right;
                q.add(new Pair(right, false));
            }
            i++;
        }
        return root;
   }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String[] nodes = new String[n];
        for(int i = 0; i < n; i++) {
            nodes[i] = sc.next();
        }
        Node root = buildTree(nodes);
        findDeepestLeftLeaf(root);
    }

    static void findDeepestLeftLeaf(Node root) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, false));
        int maxDepth = -1;
        int leftMost = -1;
        while(!q.isEmpty()) {
            int size = q.size();
            while(size-- > 0) {
                Pair p = q.poll();
                if(p.isLeft && p.node.data > maxDepth) {
                    maxDepth = p.node.data;
                    leftMost = maxDepth;
                }
                if(p.node.left != null) {
                    q.add(new Pair(p.node.left, true));
                }
                if(p.node.right != null) {
                    q.add(new Pair(p.node.right, false));
                }
            }
        }
        if(maxDepth == -1) {
            System.out.println("NONE");
        } else {
            System.out.println(leftMost);
        }
    }
}
