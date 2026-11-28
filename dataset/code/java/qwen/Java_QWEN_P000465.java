import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int diff = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        int i = 0, j = 1;
        while(j < n) {
            if(arr[j] - arr[i] == diff) { System.out.println("Yes"); return; }
            else if(arr[j] - arr[i] < diff) j++;
            else i++;
            if(i == j) j++;
        }
        System.out.println("No");
    }
}
