import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        HashMap<Integer, Integer> countMap = new HashMap<>();
        long pairs = 0;
        
        for (int num : arr) {
            int complement = target - num;
            if (countMap.containsKey(complement)) {
                pairs += countMap.get(complement);
            }
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }
        System.out.println(pairs);
    }
}
