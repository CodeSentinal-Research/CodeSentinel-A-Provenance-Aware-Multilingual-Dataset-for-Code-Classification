import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine().trim());
        String[] nums = br.readLine().trim().split(" ");

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(nums[i]);
        }

        int[] runningSum = new int[n];
        runningSum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            runningSum[i] = runningSum[i - 1] + arr[i];
        }

        for (int i = 0; i < n; i++) {
            pw.print(runningSum[i] + " ");
        }

        pw.flush();
    }
}
