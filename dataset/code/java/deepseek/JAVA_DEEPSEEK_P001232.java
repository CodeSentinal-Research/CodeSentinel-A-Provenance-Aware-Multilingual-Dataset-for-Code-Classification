import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        int[] start = new int[n];
        int[] end = new int[n];

        for (int i = 0; i < n; i++) {
            start[i] = scanner.nextInt();
        }
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            end[i] = scanner.nextInt();
        }

        System.out.println(maxActivities(start, end, n));
    }

    static int maxActivities(int start[], int end[], int n) {
        // Add a new activity
        int i, j;
        System.out.println("Activity 1");

        // Select the first activity
        i = 1;

        // Check for overlapping activity
        for (j = 0; j < n; j++) {
            if (start[j] < end[i]) {
                System.out.println("Activity " + (i + 1));
                i++;
            }
        }

        return i;
    }
}
