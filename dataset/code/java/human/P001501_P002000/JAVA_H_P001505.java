//count number of subarrays where product less than K using sliding window approach
import java.util.*;

class CountOfSubArraysProductLessThanK {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter n value ");
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println("enter k value ");
        int k = sc.nextInt();
        System.out.println(count(a, n, k));
    }

    public static int count(int a[], int n, int k) {
        int count = 0;
        int product = 1;
        int left = 0;
        for (int right = 0; right < n; right++) {
            product *= a[right];
            while (left <= right && product >= k) {
                product /= a[left];
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
}