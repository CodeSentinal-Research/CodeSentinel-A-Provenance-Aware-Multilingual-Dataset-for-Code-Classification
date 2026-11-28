import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        HashSet<Integer> set = new HashSet<>();
        int longestStreak = 0;
        int currentStreak = 0;

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            if (set.contains(num)) {
                currentStreak = 0;
            } else {
                set.add(num);
                currentStreak++;
                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        System.out.println(longestStreak);
    }
}
