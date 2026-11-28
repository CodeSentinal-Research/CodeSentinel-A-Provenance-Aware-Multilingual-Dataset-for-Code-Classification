import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        int q = sc.nextInt();
        for(int i=0; i<q; i++) {
            int x = sc.nextInt();
            boolean found = false;
            for(int num : arr) if(num == x) found = true;
            System.out.println(found ? "Found" : "Not Found");
        }
    }
}
