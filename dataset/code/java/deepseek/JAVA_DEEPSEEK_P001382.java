import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        for (int i = 0; i < N; i++) {
            set1.add(scanner.nextInt());
        }
        for (int i = 0; i < M; i++) {
            set2.add(scanner.nextInt());
        }
        set1.retainAll(set2);
        List<Integer> result = new ArrayList<>(set1);
        Collections.sort(result);
        for (int num : result) {
            System.out.println(num);
        }
    }
}
