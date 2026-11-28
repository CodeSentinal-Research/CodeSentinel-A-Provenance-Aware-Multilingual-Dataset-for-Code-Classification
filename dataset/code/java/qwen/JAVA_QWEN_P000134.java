import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        int evenIdx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                int temp = nums[evenIdx];
                nums[evenIdx] = nums[i];
                nums[i] = temp;
                evenIdx++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(nums[i]);
        }
        System.out.println();
    }
}
