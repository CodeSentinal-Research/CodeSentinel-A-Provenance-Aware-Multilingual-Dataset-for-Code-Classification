import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int target = Integer.parseInt(input[1]);
        String[] numbers = br.readLine().split(" ");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(numbers[i]);
        }
        System.out.println(countPairs(nums, target));
    }

    private static int countPairs(int[] nums, int target) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : nums) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }
        int count = 0;
        for (int num : nums) {
            if (countMap.getOrDefault(target - num, 0) > 0) {
                if (target - num == num) {
                    count += countMap.get(num) - 1;
                } else {
                    count += countMap.get(target - num);
                }
                countMap.put(num, 0);
                countMap.put(target - num, 0);
            }
        }
        return count / 2;
    }
}
