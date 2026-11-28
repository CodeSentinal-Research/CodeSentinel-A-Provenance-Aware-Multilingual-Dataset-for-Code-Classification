import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            set.add(i);
        }
        while (scanner.hasNextInt()) {
            int num = scanner.nextInt();
            set.remove(num);
        }
        for (Integer num : set) {
            System.out.println(num);
        }
    }
}
