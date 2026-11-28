import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] sweetness = new int[n];
        for(int i=0; i<n; i++) sweetness[i] = sc.nextInt();
        
        long low = Arrays.stream(sweetness).min().getAsInt();
        long high = Arrays.stream(sweetness).sum();
        
        while(low < high) {
            long mid = low + (high - low + 1) / 2;
            if(canSplit(sweetness, k + 1, mid)) low = mid;
            else high = mid - 1;
        }
        System.out.println(low);
    }
    
    static boolean canSplit(int[] sweetness, int k, long minSweetness) {
        int pieces = 0;
        long currentSum = 0;
        for(int s : sweetness) {
            currentSum += s;
            if(currentSum >= minSweetness) {
                pieces++;
                currentSum = 0;
            }
        }
        return pieces >= k;
    }
}
