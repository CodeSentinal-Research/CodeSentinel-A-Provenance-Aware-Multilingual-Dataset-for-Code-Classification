import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            left = null;
            right = null;
        }
    }

    static class Pair {
        Node node;
        int hd;

        Pair(Node node, int hd) {
            this.node = node;
            this.hd = hd;
        }
    }

    static ArrayList<Integer> topView(Node root) {
        Queue<Pair> q = new LinkedList<>();
        Map<Integer, Integer> map = new TreeMap<>();

        q.add(new Pair(root, 0));

        while(!q.isEmpty()) {
            Pair temp = q.poll();

            if(!map.containsKey(temp.hd)) {
                map.put(temp.hd, temp.node.data);
            }

            if(temp.node.left != null) {
                q.add(new Pair(temp.node.left, temp.hd-1));
           }
           }

        ArrayList<Integer> ans = new ArrayList<>(map.values());
        return ans;
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.right = new Node(4);
        root.left.right.right = new Node(5);
        root.left.right.right.right = new Node(6);

        ArrayList<Integer> res = topView(root);
        for(int i: res) {
            System.out.print(i + " ");
        }
    }
}
