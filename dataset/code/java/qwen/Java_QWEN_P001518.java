import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long success = sc.nextLong();
        int[] spells = new int[n];
        int[] potions = new int[m];
        for(int i=0; i<n; i++) spells[i] = sc.nextInt();
        for(int i=0; i<m; i++) potions[i] = sc.nextInt();
        
        Arrays.sort(potions);
        int[] res = new int[n];
        
        for(int i=0; i<n; i++) {
            long minPotion = (success + spells[i] - 1) / spells[i];
            int idx = lowerBound(potions, minPotion);
            res[i] = m - idx;
        }
        
        for(int x : res) System.out.print(x + " ");
    }
    
    static int lowerBound(int[] arr, long target) {
        int low = 0, high = arr.length;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] < target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
}
