import java.util.*;

public class Main {
    static class Pair implements Comparable<Pair> {
        int city;
        int cost;

        public Pair(int city, int cost) {
            this.city = city;
            this.cost = cost;
        }

        @Override
        public int compareTo(Pair o) {
            return this.cost - o.cost;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int S = scanner.nextInt();
        int D = scanner.nextInt();
        int K = scanner.nextInt();

        List<List<Pair>> graph = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int cost = scanner.nextInt();
            graph.get(u).add(new Pair(v, cost));
        }

        int[] dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[S] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(S, 0));

        while (!pq.isEmpty()) {
            Pair pair = pq.poll();
            int u = pair.city;
            int cost = pair.cost;

            if (cost > dist[u]) continue;

            for (Pair neighbour : graph.get(u)) {
                int v = neighbour.city;
                int edgeCost = neighbour.cost;

                if (cost + edgeCost < dist[v]) {
                    dist[v] = cost + edgeCost;
                    pq.add(new Pair(v, dist[v]));
                }
            }
        }

        if (dist[D] == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(dist[D]);
        }
    }
}
