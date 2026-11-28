import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        for(int i=0; i<n-2; i++) {
            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if(sum == target) { System.out.println("Yes"); return; }
                else if(sum < target) left++;
                else right--;
            }
        }
        System.out.println("No");
    }
}
