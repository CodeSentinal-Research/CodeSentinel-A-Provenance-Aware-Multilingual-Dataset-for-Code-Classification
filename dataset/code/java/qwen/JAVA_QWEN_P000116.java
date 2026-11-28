import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long totalSum = (long) n * (n + 1) / 2;
        long actualSum = 0;
        for (int i = 0; i < n; i++) {
            actualSum += sc.nextInt();
        }
        System.out.println(totalSum - actualSum);
    }
}
