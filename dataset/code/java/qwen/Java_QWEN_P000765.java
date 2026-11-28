import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        System.out.println(isMaxHeap(arr, 0) ? "true" : "false");
    }
    static boolean isMaxHeap(int[] arr, int i) {
        if(i >= arr.length) return true;
        int left = 2*i + 1, right = 2*i + 2;
        if(left < arr.length && arr[i] < arr[left]) return false;
        if(right < arr.length && arr[i] < arr[right]) return false;
        return isMaxHeap(arr, left) && isMaxHeap(arr, right);
    }
}
