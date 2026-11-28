import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int routes = scanner.nextInt();
        int source = scanner.nextInt();
        int target = scanner.nextInt();

        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < routes; i++) {
            int stops = scanner.nextInt();
            List<Integer> route = new ArrayList<>();
            for (int j = 0; j < stops; j++) {
                route.add(scanner.nextInt());
            }
            for (int stop : route) {
                if (!map.containsKey(stop)) {
                    map.put(stop, new ArrayList<>());
                }
                map.get(stop).addAll(route);
            }
       
           map.put(route.get(0), new ArrayList<>());
        }

        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        queue.offer(source);
        visited.add(source);
        int count = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int cur = queue.poll();
                if (cur == target) {
                    System.out.println(count);
                    return;
                }
                if (map.containsKey(cur)) {
                    for (int next : map.get(cur)) {
                        if (!visited.contains(next)) {
                            queue.offer(next);
                            visited.add(next);
                        }
                    }
                }
            }
            count++;
        }

        System.out.println(-1);
    }
}
