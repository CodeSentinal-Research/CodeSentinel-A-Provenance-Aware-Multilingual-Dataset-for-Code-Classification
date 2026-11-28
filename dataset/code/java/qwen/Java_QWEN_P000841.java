import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] candies = new int[n];
        for(int i=0; i<n; i++) candies[i] = sc.nextInt();
        long k = sc.nextLong();
        
        long low = 1, high = Arrays.stream(candies).mapToLong(i -> i).max().getAsLong();
        while(low <= high) {
            long mid = low + (high - low) / 2;
            if(canDistribute(candies, k, mid)) low = mid + 1;
            else high = mid - 1;
        }
        System.out.println(high);
    }
    static boolean canDistribute(int[] candies, long k, long perChild) {
        long count = 0;
        for(int c : candies) count += c / perChild;
        return count >= k;
    }
}
