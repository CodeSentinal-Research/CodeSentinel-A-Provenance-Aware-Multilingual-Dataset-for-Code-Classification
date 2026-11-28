import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        Map<Integer, Integer> groups = new HashMap<>();
        for(int i=1; i<=n; i++) {
            int sum = 0;
            int t = i;
            while(t > 0) {
                sum += t % 10;
                t /= 10;
            }
            groups.put(sum, groups.getOrDefault(sum, 0) + 1);
        }
        
        int maxSize = 0;
        for(int size : groups.values()) {
            maxSize = Math.max(maxSize, size);
        }
        
        int count = 0;
        for(int size : groups.values()) {
            if(size == maxSize) count++;
        }
        System.out.println(count);
    }
}
