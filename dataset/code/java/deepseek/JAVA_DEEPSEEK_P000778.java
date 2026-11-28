import java.util.*;

public class Main {
    private static int[] nums;
    private static int N;
    private static int minDiff = Integer.MAX_VALUE;
    private static int[] minPartition = new int[2];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }
        Arrays.sort(nums);
        partition(0, 0, 0, 0, new ArrayList<>(), new ArrayList<>());
        System.out.println(minDiff);
        System.out.println(Arrays.toString(minPartition));
    }

    private static void partition(int i, int sum1, int sum2, int count1, List<Integer> list1, List<Integer> list2) {
        if (i == N) {
            if (Math.abs(sum1 - sum2) < minDiff) {
                minDiff = Math.abs(sum1 - sum2);
                minPartition[0] = sum1;
                minPartition[1] = sum2;
            }
            return;
        }
        if (count1 < N / 2) {
            partition(i + 1, sum1 + nums[i], sum2, count1 + 1, list1, list2);
        }
        if (count1 > 0) {
            partition(i + 1, sum1, sum2 + nums[i], count1 - 1, list1, list2);
        }
    }
}
