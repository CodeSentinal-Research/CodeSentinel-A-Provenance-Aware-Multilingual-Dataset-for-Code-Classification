import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] height = new int[n];
        for(int i=0; i<n; i++) height[i] = sc.nextInt();
        
        int left = 0, right = n - 1;
        long maxArea = 0;
        while(left < right) {
            long area = (long)(right - left) * Math.min(height[left], height[right]);
            maxArea = Math.max(maxArea, area);
            if(height[left] < height[right]) left++;
            else right--;
        }
        System.out.println(maxArea);
    }
}
