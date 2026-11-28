import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> set1 = new HashSet<>();
        for (int i = 0; i < n; i++) {
            set1.add(scanner.nextInt());
        }
        int m = scanner.nextInt();
        Set<Integer> set2 = new HashSet<>();
        for (int i = 0; i < m; i++) {
            set2.add(scanner.nextInt());
        }
        List<Integer> list1 = new ArrayList<>(set1);
        List<Integer> list2 = new ArrayList<>(set2);
        Collections.sort(list1);
        Collections.sort(list2);
        System.out.println(list1);
        System.out.println(list2);
    }
}
