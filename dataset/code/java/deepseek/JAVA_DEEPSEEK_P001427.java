import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            int sum = sumOfDigits(i);
            if (!map.containsKey(sum)) {
                map.put(sum, new ArrayList<>());
            }
            map.get(sum).add(i);
        }
        int maxSize = 0;
        int maxGroups = 0;
        for (List<Integer> group : map.values()) {
            if (group.size() > maxSize) {
                maxSize = group.size();
                maxGroups = 1;
            } else if (group.size() == maxSize) {
                maxGroups++;
            }
        }
        System.out.println(maxGroups);
    }

    private static int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
}
