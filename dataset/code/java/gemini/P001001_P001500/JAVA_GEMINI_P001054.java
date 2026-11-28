import java.util.*;

public class Solution {
    static class Node implements Comparable<Node> {
        int sum, i, j;
        Node(int sum, int i, int j) { this.sum = sum; this.i = i; this.j = j; }
        public int compareTo(Node o) { return Integer.compare(o.sum, this.sum); }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            Integer[] b = new Integer[m];
            for (int i = 0; i < m; i++) b[i] = sc.nextInt();
            Arrays.sort(a, Collections.reverseOrder());
            Arrays.sort(b, Collections.reverseOrder());

            PriorityQueue<Node> pq = new PriorityQueue<>();
            Set<String> visited = new HashSet<>();
            pq.offer(new Node(a[0] + b[0], 0, 0));
            visited.add("0,0");

            List<Integer> res = new ArrayList<>();
            while (!pq.isEmpty() && res.size() < k) {
                Node cur = pq.poll();
                res.add(cur.sum);
                if (cur.i + 1 < n && visited.add((cur.i + 1) + "," + cur.j)) {
                    pq.offer(new Node(a[cur.i + 1] + b[cur.j], cur.i + 1, cur.j));
                }
                if (cur.j + 1 < m && visited.add(cur.i + "," + (cur.j + 1))) {
                    pq.offer(new Node(a[cur.i] + b[cur.j + 1], cur.i, cur.j + 1));
                }
            }
            for (int i = 0; i < res.size(); i++) {
                System.out.print(res.get(i) + (i == res.size() - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}