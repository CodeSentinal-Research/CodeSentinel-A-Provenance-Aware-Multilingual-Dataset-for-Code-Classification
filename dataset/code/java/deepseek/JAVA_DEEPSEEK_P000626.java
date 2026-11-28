import java.util.*;

public class Main {
    private Map<String, Integer> countMap = new HashMap<>();
    private TreeMap<Integer, Set<String>> groupMap = new TreeMap<>();

    public void inc(String key) {
        if (countMap.containsKey(key)) {
            int count = countMap.get(key);
            groupMap.get(count).remove(key);
            if (groupMap.get(count).isEmpty()) {
                groupMap.remove(count);
            }
            count++;
            countMap.put(key, count);
            groupMap.computeIfAbsent(count, k -> new HashSet<>()).add(key);
        } else {
            countMap.put(key, 1);
            groupMap.computeIfAbsent(1, k -> new HashSet<>()).add(key);
        }
    }

    public void dec(String key) {
        if (countMap.containsKey(key)) {
            int count = countMap.get(key);
            groupMap.get(count).remove(key);
            if (groupMap.get(count).isEmpty()) {
                groupMap.remove(count);
            }
            count--;
            if (count == 0) {
                countMap.remove(key);
            } else {
                countMap.put(key, count);
                groupMap.computeIfAbsent(count, k -> new HashSet<>()).add(key);
            }
        }
    }

    public String getMaxKey() {
        if (groupMap.isEmpty()) {
            return "";
        }
        return groupMap.lastEntry().getValue().iterator().next();
    }

    public String getMinKey() {
        if (groupMap.isEmpty()) {
            return "";
        }
        return groupMap.firstEntry().getValue().iterator().next();
    }

    public static void main(String[] args) {
        Main obj = new Main();
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        while (q-- > 0) {
            String operation = scanner.next();
            if (operation.equals("inc")) {
                String key = scanner.next();
                obj.inc(key);
            } else if (operation.equals("dec")) {
                String key = scanner.next();
                obj.dec(key);
            } else if (operation.equals("getMaxKey")) {
                System.out.println(obj.getMaxKey());
            } else if (operation.equals("getMinKey")) {
                System.out.println(obj.getMinKey());
            }
        }
    }
}
