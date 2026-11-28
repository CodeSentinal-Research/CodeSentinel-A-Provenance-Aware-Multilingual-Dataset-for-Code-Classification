import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] heap = new int[N];
        for (int i = 0; i < N; i++) {
            heap[i] = scanner.nextInt();
        }

        int i = scanner.nextInt();

        if (i == 0) {
            System.out.println(-1);
        } else {
            System.out.println(heap[i / 2]);
        }
    }
}
