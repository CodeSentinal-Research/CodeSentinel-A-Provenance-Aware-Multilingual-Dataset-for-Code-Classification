import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        Set<String> set = new HashSet<>();
        int count = 0;

        for (int i = 0; i < n; i++) {
            String str = scanner.nextLine();
            if (set.contains(str)) {
                count++;
            } else {
                set.add(str);
            }
        }

        System.out.println(count);
    }
}
