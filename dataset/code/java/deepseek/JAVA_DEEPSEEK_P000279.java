import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        Map<String, List<String>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String str = scanner.nextLine();
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            if (!map.containsKey(sorted)) {
                map.put(sorted, new ArrayList<>());
            }
            map.get(sorted).add(str);
       }
        for (List<String> list : map.values()) {
            System.out.println(String.join(" ", list));
        }
    }
}
