import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        boolean[] slots = new boolean[n];
        for (int i = 0; i < n; i++) {
            slots[i] = scanner.nextInt() == 0;
        }
        for (int i = 0; i < n; i++) {
            if (slots[i]) {
                System.out.println(i + 1);
            }
        }
    }
}
