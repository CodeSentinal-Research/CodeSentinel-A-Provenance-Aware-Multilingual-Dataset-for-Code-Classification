import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] diff = new int[n];
        for(int i=0; i<n; i++) diff[i] = sc.nextInt();
        
        int[] arr = new int[n];
        arr[0] = diff[0];
        for(int i=1; i<n; i++) arr[i] = arr[i-1] + diff[i];
        
        for(int x : arr) System.out.print(x + " ");
    }
}
