import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int[] nums1 = new int[m];
        for(int i=0; i<m; i++) nums1[i] = sc.nextInt();
        int n = sc.nextInt();
        int[] nums2 = new int[n];
        for(int i=0; i<n; i++) nums2[i] = sc.nextInt();
        
        if(m > n) {
            int[] temp = nums1; nums1 = nums2; nums2 = temp;
            int t = m; m = n; n = t;
        }
        
        int low = 0, high = m;
        while(low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            int maxLeft1 = partition1 == 0 ? Integer.MIN_VALUE : nums1[partition1 - 1];
            int minRight1 = partition1 == m ? Integer.MAX_VALUE : nums1[partition1];
            
            int maxLeft2 = partition2 == 0 ? Integer.MIN_VALUE : nums2[partition2 - 1];
            int minRight2 = partition2 == n ? Integer.MAX_VALUE : nums2[partition2];
            
            if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if((m + n) % 2 == 0) {
                    System.out.println((Math.max(maxLeft1, maxLeft2) + Math.min(minRight1, minRight2)) / 2.0);
                } else {
                    System.out.println(Math.max(maxLeft1, maxLeft2));
                }
                return;
            } else if(maxLeft1 > minRight2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }
    }
}
