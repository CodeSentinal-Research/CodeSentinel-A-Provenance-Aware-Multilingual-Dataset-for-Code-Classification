import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            if (set.contains(num * 2)) {
                System.out.println(-1);
                return;
            } else {
                set.add(num);
            }
        }
        List<Integer> list = new ArrayList<>(set);
        Collections.shuffle(list);
        for (int num : list) {
            System.out.println(num);
        }
    }
}
