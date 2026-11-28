import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int target = scanner.nextInt();
        int count = 0;

        for (int i = 0; i < N; i++) {
            if (scanner.nextInt() == target) {
                count++;
           }
        }

        System.out.println(count);
    }
}
