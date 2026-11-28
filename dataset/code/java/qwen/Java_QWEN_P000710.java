import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        Arrays.sort(arr);
        permuteArr(arr, 0);
    }
    static void permuteArr(int[] arr, int idx) {
        if(idx == arr.length) {
            for(int x : arr) System.out.print(x + " ");
            System.out.println();
            return;
        }
        Set<Integer> used = new HashSet<>();
        for(int i=idx; i<arr.length; i++) {
            if(used.contains(arr[i])) continue;
            used.add(arr[i]);
            swap(arr, idx, i);
            permuteArr(arr, idx + 1);
            swap(arr, idx, i);
        }
    }
    static void swap(int[] a, int i, int j) {
        int t = a[i]; a[i] = a[j]; a[j] = t;
    }
}
