import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.close();

        StringBuilder sb = new StringBuilder();
        sb.append(N);
        for (int i = 1; i <= N; i++) {
            sb.append(" ").append(i);
        }
        for (int i = 2; i <= N; i++) {
            sb.append(" ").append(i);
        }
        System.out.println(sb.toString());
    }
}
