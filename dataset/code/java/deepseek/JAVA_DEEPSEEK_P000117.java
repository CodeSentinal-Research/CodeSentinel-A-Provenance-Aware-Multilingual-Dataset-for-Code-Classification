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
            if (set.contains(num)) {
                System.out.println("Yes");
                return;
            }
            set.add(num);
        }
        System.out.println("No");
    }
}
