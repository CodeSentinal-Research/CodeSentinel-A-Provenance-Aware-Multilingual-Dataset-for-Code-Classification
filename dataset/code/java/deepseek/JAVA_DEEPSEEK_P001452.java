import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int Q = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < N; i++) {
            set.add(scanner.nextInt());
        }
        for (int i = 0; i < Q; i++) {
            int index = scanner.nextInt();
            int newValue = scanner.nextInt();
            set.remove(index);
            set.add(newValue);
            System.out.println(set.size());
        }
    }
}
