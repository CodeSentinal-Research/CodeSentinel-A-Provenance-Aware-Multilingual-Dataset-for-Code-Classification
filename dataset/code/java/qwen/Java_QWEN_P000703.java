import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        System.out.println(isPalin(arr, 0, n - 1) ? "true" : "false");
    }
    static boolean isPalin(int[] arr, int l, int r) {
        if(l >= r) return true;
        if(arr[l] != arr[r]) return false;
        return isPalin(arr, l + 1, r - 1);
    }
}
