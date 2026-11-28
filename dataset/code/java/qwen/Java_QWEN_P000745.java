import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        insSort(arr, 1, n);
        for(int x : arr) System.out.print(x + " ");
    }
    static void insSort(int[] arr, int idx, int n) {
        if(idx == n) return;
        int key = arr[idx];
        int j = idx - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        insSort(arr, idx + 1, n);
    }
}
