import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine().trim());
        String[] nums = br.readLine().split(" ");
        int[] arr = new int[n];
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(nums[i]);
        }
        int[] prefixSum = prefixSumArray(arr);
        for(int i = 0; i < n; i++) {
            pw.print(prefixSum[i] + " ");
        }
        pw.flush();
    }

    public static int[] prefixSumArray(int[] arr) {
        int n = arr.length;
        int[] prefixSum = new int[n];
        prefixSum[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
        return prefixSum;
    }
}
