import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int V = scanner.nextInt();
        scanner.nextLine();

        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < V; i++) {
            String team = scanner.nextLine();
            if (map.containsKey(team)) {
                map.put(team, map.get(team) + 1);
            } else {
                map.put(team, 1);
            }
        }

        List<String> teams = new ArrayList<>(map.keySet());
        Collections.sort(teams, (a, b) -> {
            if (map.get(a) != map.get(b)) {
                return map.get(b) - map.get(a);
            } else {
                return a.compareTo(b);
            }
        });

        for (String team : teams) {
            System.out.println(team);
        }
    }
}
