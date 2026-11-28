import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] start = new int[n];
        int[] finish = new int[n];

        for (int i = 0; i < n; i++) {
            start[i] = sc.nextInt();
            finish[i] = sc.nextInt();
        }

        System.out.println(maxActivities(start, finish, n));
    }

    static int maxActivities(int[] start, int[] finish, int n) {
        // Add your code here
        // Sort the activities according to their finishing time
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (finish[i] > finish[j]) {
                    int temp = finish[i];
                    finish[i] = finish[j];
                    finish[j] = temp;

                    temp = start[i];
                    start[i] = start[j];
                    start[j] = temp;
                }
            }
        }

        // Initialize first activity
        int i = 0;
        int count = 1;

        // Consider rest of the activities
        for (int j = 1; j < n; j++) {
            // If this activity has start time greater than
            // or equal to the finish time of previously
            // selected activity, then select it
            if (start[j] >= finish[i]) {
                i = j;
                count++;
            }
        }

        return count;
    }
}
