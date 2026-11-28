import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        boolean found = false;

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            if (set.contains(2 * num)) {
                found = true;
                System.out.println("YES");
                break;
            }
            set.add(num);
        }

        if (!found) {
            System.out.println("NO");
        }
    }
}
