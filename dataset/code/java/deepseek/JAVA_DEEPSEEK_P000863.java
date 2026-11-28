import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int[] result = singleNumber(nums);
        System.out.println(result[0] + " " + result[1]);
    }

    public static int[] singleNumber(int[] nums) {
        int bitwiseXOR = 0;
        for (int num : nums) {
            bitwiseXOR ^= num;
        }
        int rightmostSetBit = bitwiseXOR & -bitwiseXOR;
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if ((num & rightmostSetBit) != 0) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        return new int[]{num1, num2};
    }
}
