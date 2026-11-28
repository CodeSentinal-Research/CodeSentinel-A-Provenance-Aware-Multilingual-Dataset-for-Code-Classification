import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        System.out.println(findMax(arr, 0, Integer.MIN_VALUE));
    }
    static int findMax(int[] arr, int i, int max) {
        if(i >= arr.length) return max;
        return findMax(arr, i + 1, Math.max(max, arr[i]));
    }
}
