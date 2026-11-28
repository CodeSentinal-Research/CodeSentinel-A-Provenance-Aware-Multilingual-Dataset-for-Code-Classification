import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long[] distances = new long[N];
        long[] speeds = new long[N];
        for (int i = 0; i < N; i++) {
            distances[i] = scanner.nextLong();
        }
        for (int i = 0; i < N; i++) {
            speeds[i] = scanner.nextLong();
        }
        scanner.close();
        long maxMonsters = 0;
        for (int i = 0; i < N; i++) {
            maxMonsters = Math.max(maxMonsters, distances[i] % speeds[i]);
        }
        System.out.println(maxMonsters);
    }
}
