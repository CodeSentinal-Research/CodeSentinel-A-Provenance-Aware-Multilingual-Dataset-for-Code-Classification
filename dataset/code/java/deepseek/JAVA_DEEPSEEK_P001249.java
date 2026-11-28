import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] ropes = new long[n];
        long totalCost = 0;

        for (int i = 0; i < n; i++) {
            ropes[i] = scanner.nextLong();
        }

        while (n > 1) {
            long rope1 = ropes[0];
            long rope2 = ropes[1];
            totalCost += rope1 + rope2;
            ropes[0] = rope1 + rope2;
            ropes[1] = 0;
            java.util.Arrays.sort(ropes);
            n--;
        }

        System.out.println(totalCost);
    }
}
