import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int k = scanner.nextInt();
            List<Integer> allVals = new ArrayList<>();
            for (int i = 0; i < k; i++) {
                int size = scanner.nextInt();
                for (int j = 0; j < size; j++) allVals.add(scanner.nextInt());
            }
            Collections.sort(allVals);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < allVals.size(); i++) {
                sb.append(allVals.get(i)).append(i + 1 == allVals.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}