import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        int maxLen = 0;
        int negCount = 0;
        int firstNeg = -1;
        int lastNeg = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                negCount++;
                if (firstNeg == -1) firstNeg = i;
                lastNeg = i;
            }
            
            if (negCount % 2 == 0) {
                maxLen = Math.max(maxLen, i + 1);
            } else {
                maxLen = Math.max(maxLen, i - firstNeg);
            }
        }
        System.out.println(maxLen);
    }
}
