import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int r = scanner.nextInt();
            List<List<Integer>> routes = new ArrayList<>();
            Map<Integer, List<Integer>> stopToRoutes = new HashMap<>();
            for (int i = 0; i < r; i++) {
                int k = scanner.nextInt();
                List<Integer> route = new ArrayList<>();
                for (int j = 0; j < k; j++) {
                    int stop = scanner.nextInt();
                    route.add(stop);
                    stopToRoutes.computeIfAbsent(stop, x -> new ArrayList<>()).add(i);
                }
                routes.add(route);
            }
            int source = scanner.nextInt(), target = scanner.nextInt();
            if (source == target) { System.out.println(0); return; }
            Queue<int[]> q = new LinkedList<>();
            Set<Integer> visStops = new HashSet<>();
            boolean[] visRoutes = new boolean[r];
            q.add(new int[]{source, 0});
            visStops.add(source);
            int ans = -1;
            while (!q.isEmpty()) {
                int[] cur = q.poll();
                int stop = cur[0], buses = cur[1];
                for (int bus : stopToRoutes.getOrDefault(stop, Collections.emptyList())) {
                    if (!visRoutes[bus]) {
                        visRoutes[bus] = true;
                        for (int nxt : routes.get(bus)) {
                            if (nxt == target) { ans = buses + 1; break; }
                            if (!visStops.contains(nxt)) {
                                visStops.add(nxt);
                                q.add(new int[]{nxt, buses + 1});
                            }
                        }
                    }
                    if (ans != -1) break;
                }
                if (ans != -1) break;
            }
            System.out.println(ans);
        }
    }
}