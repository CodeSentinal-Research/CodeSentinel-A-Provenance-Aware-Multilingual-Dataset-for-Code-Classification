import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int limit = sc.nextInt();
        int[] weights = new int[n];
        for(int i=0; i<n; i++) weights[i] = sc.nextInt();
        
        Arrays.sort(weights);
        int boats = 0;
        int left = 0, right = n - 1;
        while(left <= right) {
            if(weights[left] + weights[right] <= limit) {
                left++;
            }
            right--;
            boats++;
        }
        System.out.println(boats);
    }
}
