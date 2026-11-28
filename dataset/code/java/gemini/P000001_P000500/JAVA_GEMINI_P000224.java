import java.util.Arrays;

class Job {
    int id, profit, deadline;
    Job(int x, int y, int z) { this.id = x; this.deadline = y; this.profit = z; }
}

public class Solution {
    public int[] JobScheduling(Job[] arr, int n) {
        Arrays.sort(arr, (a, b) -> b.profit - a.profit);
        int maxD = 0;
        for (Job j : arr) if (j.deadline > maxD) maxD = j.deadline;

        int[] slot = new int[maxD + 1];
        Arrays.fill(slot, -1);

        int count = 0, totalProfit = 0;
        for (Job j : arr) {
            for (int d = j.deadline; d > 0; d--) {
                if (slot[d] == -1) {
                    slot[d] = j.id;
                    count++;
                    totalProfit += j.profit;
                    break;
                }
            }
        }
        return new int[]{count, totalProfit};
    }
}