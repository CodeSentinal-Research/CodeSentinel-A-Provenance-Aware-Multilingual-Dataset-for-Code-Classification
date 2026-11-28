import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        int Q = scanner.nextInt();
        for (int i = 0; i < Q; i++) {
            int index = scanner.nextInt() - 1;
            int value = scanner.nextInt();
            if (arr[index] < value) {
                System.out.println("INVALID");
                return;
            }
            arr[index] = value;
        }
        System.out.println("VALID");
    }
}
