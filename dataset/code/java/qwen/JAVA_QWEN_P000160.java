import java.util.Scanner;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        HashSet<Integer> set = new HashSet<>();
        boolean found = false;
        
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            if (set.contains(target - num)) {
                found = true;
            }
            set.add(num);
        }
        System.out.println(found ? "Yes" : "No");
    }
}
