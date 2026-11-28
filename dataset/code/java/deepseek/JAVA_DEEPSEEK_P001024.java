import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }

        int i = scanner.nextInt();

        if (i == 0) {
            if (arr[i] == -1) {
                System.out.println("-1 -1");
            } else {
                System.out.println(arr[i] + " " + arr[i + 1]);
            }
        } else {
            if (arr[i - 1] == -1) {
                System.out.println("-1 -1");
            } else {
                System.out.println(arr[i - 1] + " " + arr[i]);
            }
        }

        scanner.close();
    }
}
