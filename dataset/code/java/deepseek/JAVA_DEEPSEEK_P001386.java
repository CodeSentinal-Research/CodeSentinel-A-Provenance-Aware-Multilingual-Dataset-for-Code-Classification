import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        int duplicate = -1;
        for (int i = 1; i <= n; i++) {
            int num = scanner.nextInt();
            if (set.contains(num)) {
                duplicate = num;
            } else {
                set.add(num);
            }
        }
        System.out.println(duplicate);
    }
}
