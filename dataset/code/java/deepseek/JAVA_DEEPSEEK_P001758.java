import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> values = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            if (values.contains(value)) {
                System.out.println("YES");
                return;
            }
            values.add(value);
        }
        System.out.println("NO");
    }
}
