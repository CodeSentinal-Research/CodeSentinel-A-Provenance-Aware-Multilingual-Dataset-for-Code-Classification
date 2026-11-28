import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        int target = sc.nextInt();
        System.out.println(linearSearch(arr, 0, target) ? "true" : "false");
    }
    static boolean linearSearch(int[] arr, int i, int target) {
        if(i >= arr.length) return false;
        if(arr[i] == target) return true;
        return linearSearch(arr, i + 1, target);
    }
}
