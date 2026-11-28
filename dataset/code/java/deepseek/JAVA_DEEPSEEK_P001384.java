import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> duplicates = new HashSet<>();
        Set<Integer> found = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            if (found.contains(num)) {
                duplicates.add(num);
            } else {
                found.add(num);
            }
        }
        List<Integer> duplicatesList = new ArrayList<>(duplicates);
        Collections.sort(duplicatesList);
        for (int num : duplicatesList) {
            System.out.println(num);
        }
    }
}
