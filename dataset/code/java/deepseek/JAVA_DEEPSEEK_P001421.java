import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<String> list1 = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list1.add(scanner.next());
        }
        int m = scanner.nextInt();
        List<String> list2 = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            list2.add(scanner.next());
        }
        Map<String, Integer> map = new HashMap<>();
        for (String s : list1) {
            for (String t : list2) {
                if (s.equals(t)) {
                    map.put(s, map.getOrDefault(s, 0) + 1);
                }
            }
        }
        List<String> result = new ArrayList<>();
        int min = Integer.MAX_VALUE;
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            if (entry.getValue() > 1) {
                result.add(entry.getKey());
                min = Math.min(min, entry.getKey().length() + entry.getValue() - 1);
            }
        }
        if (min == Integer.MAX_VALUE) {
            System.out.println("No common strings found");
        } else {
            Collections.sort(result);
            for (String s : result) {
                if (s.length() + map.get(s) - 1 == min) {
                    System.out.println(s);
                }
            }
        }
    }
}
