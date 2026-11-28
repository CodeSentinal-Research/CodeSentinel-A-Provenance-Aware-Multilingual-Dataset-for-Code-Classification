import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }
        int Q = scanner.nextInt();
        while (Q-- > 0) {
            int L = scanner.nextInt();
            int R = scanner.nextInt();
            int X = scanner.nextInt();
            int count = 0;
            for (int i = L; i <= R; i++) {
                if (nums[i] % X == 0) {
                    count++;
               }
            }
            System.out.println(count);
        }
    }
}
