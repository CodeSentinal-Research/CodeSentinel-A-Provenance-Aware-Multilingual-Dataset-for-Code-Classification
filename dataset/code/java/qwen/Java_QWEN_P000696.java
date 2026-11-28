import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        int target = sc.nextInt();
        System.out.println(lastOcc(arr, 0, n - 1, target));
    }
    static int lastOcc(int[] arr, int low, int high, int target) {
        if(low > high) return -1;
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            if(mid == arr.length - 1 || arr[mid + 1] != target) return mid;
            else return lastOcc(arr, mid + 1, high, target);
        } else if(arr[mid] < target) return lastOcc(arr, mid + 1, high, target);
        else return lastOcc(arr, low, mid - 1, target);
    }
}
