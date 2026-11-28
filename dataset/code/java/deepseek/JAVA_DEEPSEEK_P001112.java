import java.util.*;

public class Main {
    static int N, M;
    static String start, end;
    static HashSet<String> set;
    static HashMap<String, ArrayList<String>> map;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        sc.nextLine();
        set = new HashSet<>();
        map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            String s = sc.nextLine();
            set.add(s);
            map.putIfAbsent(s, new ArrayList<>());
        }
        start = sc.nextLine();
        end = sc.nextLine();
        System.out.println(minTransfers(start, end));
    }

    static int minTransfers(String start, String end) {
        if (start.equals(end)) return 0;
        ArrayList<String> next = map.get(start);
        if (next == null) return Integer.MAX_VALUE;
        int min = Integer.MAX_VALUE;
        for (String s : next) {
            int cost = minTransfers(s, end);
            if (cost != Integer.MAX_VALUE) {
                min = Math.min(min, cost + 1);
            }
        }
        return min == Integer.MAX_VALUE ? Integer.MAX_VALUE : min;
    }
}
