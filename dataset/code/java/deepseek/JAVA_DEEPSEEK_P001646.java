import java.util.*;
import java.io.*;

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
        int min;
        int max;

        Pair(Node node, int min, int max) {
            this.node = node;
            this.min = min;
            this.max = max;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] s = br.readLine().split(" ");
            Node root = new Node(Integer.parseInt(s[0]));
            PriorityQueue<Pair> queue = new PriorityQueue<>(new Comparator<Pair>() {
                public int compare(Pair a, Pair b) {
                    return a.min - b.min;
                }
            });
            queue.add(new Pair(root, 0, 0));
            Map<Integer, Integer> map = new HashMap<>();
            while (!queue.isEmpty()) {
                Pair p = queue.poll();
                if (!map.containsKey(p.max)) {
                    map.put(p.max, p.node.data);
                }
                if (p.node.left != null) {
                    queue.add(new Pair(p.node.left, p.min - 1, p.max + 1));
                }
                if (p.node.right != null) {
                    queue.add(new Pair(p.node.right, p.min + 1, p.max + 1));
                }
            }
            for (int i : map.values()) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
