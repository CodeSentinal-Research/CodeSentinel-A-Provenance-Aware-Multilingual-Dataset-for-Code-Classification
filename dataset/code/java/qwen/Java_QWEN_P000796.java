import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        long total = 0;
        for(int i=0; i<n; i++) {
            nums[i] = sc.nextInt();
            total += nums[i];
        }
        int p = sc.nextInt();
        if(total % p == 0) { System.out.println(0); return; }
        long target = total % p;
        Map<Long, Integer> map = new HashMap<>();
        map.put(0L, -1);
        long sum = 0;
        int minLen = n;
        for(int i=0; i<n; i++) {
            sum = (sum + nums[i]) % p;
            long need = (sum - target + p) % p;
            if(map.containsKey(need)) {
                minLen = Math.min(minLen, i - map.get(need));
            }
            map.put(sum, i);
        }
        System.out.println(minLen == n ? -1 : minLen);
    }
}
