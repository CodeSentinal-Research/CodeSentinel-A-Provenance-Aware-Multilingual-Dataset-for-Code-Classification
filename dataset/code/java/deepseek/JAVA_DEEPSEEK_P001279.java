import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        StringBuilder sb = new StringBuilder();
        K -= N;
        for (int i = 0; i < N; i++) {
            sb.append('a');
        }
        sb.append('b');
        String result = sb.toString();
        System.out.println(result);
    }
}
