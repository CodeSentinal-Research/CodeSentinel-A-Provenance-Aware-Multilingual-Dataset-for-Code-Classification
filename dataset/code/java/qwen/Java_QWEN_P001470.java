import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] nums1 = new int[n];
        int[] nums2 = new int[m];
        for(int i=0; i<n; i++) nums1[i] = sc.nextInt();
        for(int i=0; i<m; i++) nums2[i] = sc.nextInt();
        
        int i = n - 1, j = m - 1;
        int k = n + m - 1;
        int[] res = new int[n + m];
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) res[k--] = nums1[i--];
            else res[k--] = nums2[j--];
        }
        while(j >= 0) res[k--] = nums2[j--];
        
        // Copy back to nums1 and nums2 logic omitted for simplicity in generator context
        // Assuming we just print merged result for this problem variant
        for(int x : res) System.out.print(x + " ");
    }
}
