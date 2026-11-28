import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        boolean[] visited = new boolean[n + 1];
        ArrayList<Integer> duplicates = new ArrayList<>();
        
        for (int num : nums) {
            if (visited[num]) {
                duplicates.add(num);
            } else {
                visited[num] = true;
            }
        }
        
        for (int i = 0; i < duplicates.size(); i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(duplicates.get(i));
        }
        System.out.println();
    }
}
