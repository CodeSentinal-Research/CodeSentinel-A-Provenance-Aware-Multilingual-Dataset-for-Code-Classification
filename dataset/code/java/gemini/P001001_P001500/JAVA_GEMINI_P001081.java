import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            int[] deg = new int[n];
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
            Map<Long, Integer> edgeCount = new HashMap<>();

            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj.get(u).add(v);
                adj.get(v).add(u);
                deg[u]++;
                deg[v]++;
                long k1 = (((long)u) << 32) | v;
                long k2 = (((long)v) << 32) | u;
                edgeCount.put(k1, edgeCount.getOrDefault(k1, 0) + 1);
                edgeCount.put(k2, edgeCount.getOrDefault(k2, 0) + 1);
            }

            boolean ok = true;
            for (int d : deg) if (d % 2 != 0) { ok = false; break; }

            if (!ok) {
                System.out.println("NONE");
            } else {
                Stack<Integer> stack = new Stack<>();
                List<Integer> circuit = new ArrayList<>();
                stack.push(0);

                while (!stack.isEmpty()) {
                    int u = stack.peek();
                    boolean hasEdge = false;
                    for (int v : adj.get(u)) {
                        long k1 = (((long)u) << 32) | v;
                        long k2 = (((long)v) << 32) | u;
                        if (edgeCount.getOrDefault(k1, 0) > 0) {
                            edgeCount.put(k1, edgeCount.get(k1) - 1);
                            edgeCount.put(k2, edgeCount.get(k2) - 1);
                            stack.push(v);
                            hasEdge = true;
                            break;
                        }
                    }
                    if (!hasEdge) circuit.add(stack.pop());
                }
                Collections.reverse(circuit);
                for (int i = 0; i < circuit.size(); i++) {
                    System.out.print(circuit.get(i) + (i == circuit.size() - 1 ? "" : " "));
                }
                System.out.println();
            }
        }
        sc.close();
    }
}