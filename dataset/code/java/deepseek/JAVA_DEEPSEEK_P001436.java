import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(maxBalloons(input));
    }

    public static int maxBalloons(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        int e = map.get('o');
        int n = map.get('n');
        int b = map.get('b');

        if (e == 0 || n == 0 || b == 0) {
            return 0;
        }

        int e_times_b = e / b;
        int e_times_n = e / n;

        int maxTimes = Math.max(e_times_b, e_times_n);

        return maxTimes;
    }
}
