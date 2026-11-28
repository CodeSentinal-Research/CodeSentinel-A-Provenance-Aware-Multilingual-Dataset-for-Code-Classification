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
        
        int[] res = new int[n + m];
        int i = 0, j = 0, k = 0;
        while(i < n && j < m) {
            if(nums1[i] <= nums2[j]) res[k++] = nums1[i++];
            else res[k++] = nums2[j++];
        }
        while(i < n) res[k++] = nums1[i++];
        while(j < m) res[k++] = nums2[j++];
        
        for(int x : res) System.out.print(x + " ");
    }
}
