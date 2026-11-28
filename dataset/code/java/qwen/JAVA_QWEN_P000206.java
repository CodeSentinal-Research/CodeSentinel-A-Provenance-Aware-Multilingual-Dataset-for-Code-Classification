import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[] arr1 = new int[m];
        int[] arr2 = new int[n];
        
        for (int i = 0; i < m; i++) arr1[i] = sc.nextInt();
        for (int i = 0; i < n; i++) arr2[i] = sc.nextInt();
        
        // Binary search approach for O(log(min(m,n)))
        if (m > n) {
            // Ensure arr1 is the smaller one
            int[] tempArr = arr1; arr1 = arr2; arr2 = tempArr;
            int tempM = m; m = n; n = tempM;
        }
        
        int low = 0, high = m;
        double median = 0;
        
        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            int maxLeft1 = (partition1 == 0) ? Integer.MIN_VALUE : arr1[partition1 - 1];
            int minRight1 = (partition1 == m) ? Integer.MAX_VALUE : arr1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? Integer.MIN_VALUE : arr2[partition2 - 1];
            int minRight2 = (partition2 == n) ? Integer.MAX_VALUE : arr2[partition2];
            
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 0) {
                    median = (Math.max(maxLeft1, maxLeft2) + Math.min(minRight1, minRight2)) / 2.0;
                } else {
                    median = Math.max(maxLeft1, maxLeft2);
                }
                break;
            } else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }
        
        System.out.println(median);
    }
}
