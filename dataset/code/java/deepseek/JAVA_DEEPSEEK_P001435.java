import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();
        Set<String> set1 = new HashSet<>();
        Set<String> set2 = new HashSet<>();
        for (int i = 0; i < N; i++) {
            set1.add(scanner.nextLine());
        }
        N = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < N; i++) {
            set2.add(scanner.nextLine());
        }
        int count = 0;
        for (String word : set1) {
            if (set2.contains(word)) {
                count++;
            }
        }
        System.out.println(count);
    }
}
