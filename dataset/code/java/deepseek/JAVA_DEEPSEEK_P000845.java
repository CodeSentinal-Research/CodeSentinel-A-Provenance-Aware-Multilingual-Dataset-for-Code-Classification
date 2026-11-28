import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        String[] firstLine = br.readLine().split(" ");
        int n = Integer.parseInt(firstLine[0]);
        int k = Integer.parseInt(firstLine[1]);

        int[] nums = new int[n];
        String[] numsStr = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(numsStr[i]);
        }

        pw.println(minCapability(nums, k));
        pw.flush();
    }

    public static int minCapability(int[] nums, int k) {
        int left = 1;
        int right = (int)1e9;

        while (left < right) {
            int mid = (left + right) / 2;
            if (canRob(nums, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    private static boolean canRob(int[] nums, int k, int cap) {
        int n = nums.length;
        int rob = 0, notRob = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] <= cap) {
                int temp = rob;
                rob = notRob + nums[i];
                notRob = Math.max(temp, notRob);
            } else {
                rob = notRob;
                notRob = Math.max(rob, notRob);
            }
        }

        return rob >= k;
    }
}
