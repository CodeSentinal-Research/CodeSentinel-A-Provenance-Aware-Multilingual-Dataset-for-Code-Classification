import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] petrol = new long[n];
        long[] distance = new long[n];
        for (int i = 0; i < n; i++) {
            petrol[i] = scanner.nextLong();
        }
        for (int i = 0; i < n; i++) {
            distance[i] = scanner.nextLong();
       }
        System.out.println(tour(petrol, distance));
    }

    public static int tour(long[] petrol, long[] distance) {
        int n = petrol.length;
        long deficit = 0;
        long balance = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            balance += petrol[i] - distance[i];
            if (balance < 0) {
                deficit += balance;
                balance = 0;
                start = i + 1;
            }
        }
        return balance + deficit >= 0 ? start : -1;
    }
}
