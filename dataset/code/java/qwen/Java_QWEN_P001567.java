import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        Set<Integer> distinctSet = new HashSet<>();
        for(int i=0; i<n; i++) {
            nums[i] = sc.nextInt();
            distinctSet.add(nums[i]);
        }
        int totalDistinct = distinctSet.size();
        
        Map<Integer, Integer> windowMap = new HashMap<>();
        int count = 0;
        int left = 0;
        int distinctInWindow = 0;
        
        for(int right=0; right<n; right++) {
            windowMap.put(nums[right], windowMap.getOrDefault(nums[right], 0) + 1);
            if(windowMap.get(nums[right]) == 1) distinctInWindow++;
            
            while(distinctInWindow == totalDistinct) {
                count += (n - right);
                windowMap.put(nums[left], windowMap.get(nums[left]) - 1);
                if(windowMap.get(nums[left]) == 0) distinctInWindow--;
                left++;
            }
        }
        System.out.println(count);
    }
}
