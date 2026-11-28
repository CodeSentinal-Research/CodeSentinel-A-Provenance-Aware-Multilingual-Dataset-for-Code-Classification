import java.util.Scanner;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        HashSet<Integer> set = new HashSet<>();
        boolean hasDuplicate = false;
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            if (!set.add(val)) {
                hasDuplicate = true;
            }
        }
        System.out.println(hasDuplicate ? "Yes" : "No");
    }
}
