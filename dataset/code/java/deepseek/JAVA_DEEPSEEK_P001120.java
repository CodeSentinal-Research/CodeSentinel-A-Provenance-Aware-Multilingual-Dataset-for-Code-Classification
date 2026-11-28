import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        TreeMap<String, List<String>> map = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            String[] ticket = scanner.nextLine().split(" ");
            String departure = ticket[0];
            String arrival = ticket[1];

            if (map.containsKey(departure)) {
                map.get(departure).add(arrival);
            } else {
                ArrayList<String> list = new ArrayList<>();
                list.add(arrival);
                map.put(departure, list);
            }
        }

        PriorityQueue<String> queue = new PriorityQueue<>((a, b) -> map.get(a).size() - map.get(b).size());
        queue.addAll(map.keySet());

        StringBuilder sb = new StringBuilder();
        while (!queue.isEmpty()) {
            String airport = queue.poll();
            while (!queue.isEmpty() && map.get(queue.peek()).size() > 0) {
                queue.poll();
            }
            sb.append(airport).append(" ");

            if (!queue.isEmpty()) {
                String nextAirport = queue.poll();
                queue.add(nextAirport);
            }
        }

        System.out.println(sb.toString().trim());
    }
}
