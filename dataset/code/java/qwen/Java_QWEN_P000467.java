import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[] nums1 = new int[m];
        int[] nums2 = new int[n];
        for(int i=0; i<m; i++) nums1[i] = sc.nextInt();
        for(int i=0; i<n; i++) nums2[i] = sc.nextInt();
        
        int total = m + n;
        if(total % 2 == 1) {
            System.out.println(findKth(nums1, nums2, total / 2 + 1));
        } else {
            double v1 = findKth(nums1, nums2, total / 2);
            double v2 = findKth(nums1, nums2, total / 2 + 1);
            System.out.println((v1 + v2) / 2.0);
        }
    }
    static double findKth(int[] a, int[] b, int k) {
        int m = a.length, n = b.length;
        if(m > n) return findKth(b, a, k);
        if(m == 0) return b[k - 1];
        if(k == 1) return Math.min(a[0], b[0]);
        
        int i = Math.min(m, k / 2);
        int j = k - i;
        if(a[i - 1] < b[j - 1]) {
            int[] na = Arrays.copyOfRange(a, i, m);
            return findKth(na, b, k - i);
        } else {
            int[] nb = Arrays.copyOfRange(b, j, n);
            return findKth(a, nb, k - j);
        }
    }
}
