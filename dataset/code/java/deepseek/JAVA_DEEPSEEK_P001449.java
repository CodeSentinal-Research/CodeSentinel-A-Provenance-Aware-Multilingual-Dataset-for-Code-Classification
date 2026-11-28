import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            set.add(num);
        }
        int max = -1;
        for (int num : set) {
            if (set.contains(-num)) {
                max = Math.max(max, num);
            }
        }
        System.out.println(max);
    }
}
