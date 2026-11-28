import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Job[] jobs = new Job[n];
        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            int deadline = sc.nextInt();
            int profit = sc.nextInt();
            jobs[i] = new Job(id, deadline, profit);
        }
        printJobScheduling(jobs, n);
    }

    static void printJobScheduling(Job arr[], int n) {
        Arrays.sort(arr, new Comparator<Job>() {
            @Override
            public int compare(Job a, Job b) {
                return b.profit - a.profit;
           
            }
        });

        int result[] = new int[n];
        boolean slot[] = new boolean[n];

        for (int i=0; i<n; i++) {
            for (int j = Math.min(n, arr[i].deadline) - 1; j>=0; j--) {
                if (!slot[j]) {
                    result[j] = i;
                    slot[j] = true;
                    break;
                }
            }
        }

        int maxProfit = 0;
        int count = 0;
        for (int i=0; i<n; i++) {
            if (slot[i]) {
                maxProfit += arr[result[i]].profit;
                count++;
            }
        }

        System.out.println(maxProfit + " " + count);
    }

    static class Job {
        int id, deadline, profit;
        Job(int x, int y, int z) {
            id = x;
            deadline = y;
            profit = z;
        }
    }
}
