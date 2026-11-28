import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<String> set = new HashSet<>();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int[] domino = new int[2];
            domino[0] = scanner.nextInt();
            domino[1] = scanner.nextInt();
            Arrays.sort(domino);
            String key = Arrays.toString(domino);
            if (set.contains(key)) {
                count++;
            } else {
                set.add(key);
            }
        }
        System.out.println(count);
    }
}
