import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        reverseArr(arr, 0, n - 1);
        for(int x : arr) System.out.print(x + " ");
    }
    static void reverseArr(int[] arr, int l, int r) {
        if(l >= r) return;
        int t = arr[l]; arr[l] = arr[r]; arr[r] = t;
        reverseArr(arr, l + 1, r - 1);
    }
}
