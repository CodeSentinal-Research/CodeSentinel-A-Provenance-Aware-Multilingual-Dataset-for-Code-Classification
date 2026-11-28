import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        System.out.println(findMin(arr, 0, Integer.MAX_VALUE));
    }
    static int findMin(int[] arr, int i, int min) {
        if(i >= arr.length) return min;
        return findMin(arr, i + 1, Math.min(min, arr[i]));
    }
}
