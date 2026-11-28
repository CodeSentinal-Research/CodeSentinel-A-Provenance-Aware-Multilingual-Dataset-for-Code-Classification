import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        int count = 0;
        for (int i = 0; i < n; i++) {
            int x1 = scanner.nextInt();
            int y1 = scanner.nextInt();
            scanner.nextLine();

            int[] points = new int[n];
            for (int j = 0; j < n; j++) {
                int x2 = scanner.nextInt();
                int y2 = scanner.nextInt();
                scanner.nextLine();

                int distance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                points[j] = distance;
            }

            for (int j = 0; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (points[j] == points[k]) {
                        count++;
                    }
                }
            }
        }

        System.out.println(count);
    }
}
