import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n + 1; i++) {
            int num = scanner.nextInt();
            if (set.contains(num)) {
                System.out.println(num);
                break;
            }
            set.add(num);
        }
    }
}
