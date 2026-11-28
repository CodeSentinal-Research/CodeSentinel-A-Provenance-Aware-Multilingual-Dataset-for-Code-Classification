import java.util.Scanner;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(subarrayBitwiseORs(nums));
    }

    public static int subarrayBitwiseORs(int[] A) {
        HashSet<Integer> ans = new HashSet<>();
        for (int i = 0; i < A.length; i++) {
            int val = 0;
            for (int j = i; j < A.length; j++) {
                val |= A[j];
                ans.add(val);
            }
        }
        return ans.size();
    }
}
