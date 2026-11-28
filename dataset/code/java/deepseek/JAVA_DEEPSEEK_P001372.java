import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        boolean duplicate = false;

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            if (set.contains(num)) {
                duplicate = true;
                break;
            }
            set.add(num);
        }

        if (duplicate) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
