import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        selSort(arr, 0, n);
        for(int x : arr) System.out.print(x + " ");
    }
    static void selSort(int[] arr, int idx, int n) {
        if(idx == n) return;
        int minIdx = idx;
        for(int i=idx+1; i<n; i++) {
            if(arr[i] < arr[minIdx]) minIdx = i;
        }
        int t = arr[idx]; arr[idx] = arr[minIdx]; arr[minIdx] = t;
        selSort(arr, idx + 1, n);
    }
}
