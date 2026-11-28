import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums1 = new int[n];
        for(int i=0; i<n; i++) nums1[i] = sc.nextInt();
        int m = sc.nextInt();
        int[] nums2 = new int[m];
        for(int i=0; i<m; i++) nums2[i] = sc.nextInt();
        
        Map<Integer, Integer> nextGreater = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        for(int num : nums2) {
            while(!stack.isEmpty() && stack.peek() < num) {
                nextGreater.put(stack.pop(), num);
            }
            stack.push(num);
        }
        for(int num : nums1) {
            System.out.print(nextGreater.getOrDefault(num, -1) + " ");
        }
    }
}
