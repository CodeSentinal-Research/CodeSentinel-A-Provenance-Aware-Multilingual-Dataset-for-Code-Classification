import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] price = new int[n];
        for(int i=0; i<n; i++) price[i] = sc.nextInt();
        int k = sc.nextInt();
        Arrays.sort(price);
        
        int low = 0, high = price[n-1] - price[0];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canSelect(price, k, mid)) low = mid + 1;
            else high = mid - 1;
        }
        System.out.println(high);
    }
    static boolean canSelect(int[] price, int k, int minTaste) {
        int count = 1, lastIdx = 0;
        for(int i=1; i<price.length; i++) {
            if(price[i] - price[lastIdx] >= minTaste) {
                count++;
                lastIdx = i;
                if(count == k) return true;
            }
        }
        return false;
    }
}
