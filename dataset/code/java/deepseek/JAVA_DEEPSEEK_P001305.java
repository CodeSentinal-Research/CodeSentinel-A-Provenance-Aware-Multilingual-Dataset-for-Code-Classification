import java.util.*;

public class Main {
    static class Node implements Comparable<Node> {
        long freq;
        String code;
        Node left, right;

        public Node(long freq, String code, Node left, Node right) {
            this.freq = freq;
            this.code = code;
            this.left = left;
            this.right = right;
        }

        @Override
        public int compareTo(Node other) {
            return Long.compare(this.freq, other.freq);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] freqs = new long[n];
        for (int i = 0; i < n; i++) {
            freqs[i] = scanner.nextLong();
        }
        PriorityQueue<Node> queue = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            queue.add(new Node(freqs[i], String.valueOf(i + 1), null, null));
        }
        while (queue.size() != 1) {
            Node left = queue.poll();
            Node right = queue.poll();
            long freq = left.freq + right.freq;
            String code = left.code + right.code;
            queue.add(new Node(freq, code, left, right));
        }
        Node root = queue.poll();
        long cost = getCost(root, "");
        System.out.println(cost);
    }

    private static long getCost(Node node, String str) {
        if (node.left == null && node.right == null) {
            return str.length() * node.freq;
        } else {
            return getCost(node.left, str + "0") + getCost(node.right, str + "1");
        }
    }
}
