import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            set.add(scanner.nextInt());
        }
        scanner.close();
        
        if (set.size() == n) {
            System.out.println("No");
            return;
        }
        
        List<Integer> list = new ArrayList<>(set);
        Collections.sort(list);
        
        for (int i = 0; i < list.size() - 1; i++) {
            if (list.get(i + 1) - list.get(i) != 1) {
                System.out.println("No");
                return;
           }
        }
        
        System.out.println("Yes");
    }
}
