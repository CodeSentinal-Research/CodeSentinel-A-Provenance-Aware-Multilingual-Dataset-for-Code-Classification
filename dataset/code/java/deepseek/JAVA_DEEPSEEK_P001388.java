import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(scanner.nextInt());
        }
        scanner.close();
        List<Integer> distinctElements = new ArrayList<>();
        for (int i = 0; i <= list.size() - k; i++) {
            Set<Integer> set = new HashSet<>();
            for (int j = i; j < i + k; j++) {
                set.add(list.get(j));
            }
            distinctElements.add(set.size());
        }
        for (int i : distinctElements) {
            System.out.println(i);
        }
    }
}
