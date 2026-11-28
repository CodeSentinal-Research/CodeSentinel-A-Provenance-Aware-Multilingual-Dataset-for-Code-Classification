import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        Map<String, List<String>> map = new HashMap<>();
        while (n-- > 0) {
            String str = scanner.nextLine();
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sortedStr = new String(chars);

            if (!map.containsKey(sortedStr)) {
                map.put(sortedStr, new ArrayList<>());
            }

            map.get(sortedStr).add(str);
        }

        for (List<String> group : map.values()) {
            Collections.sort(group);
            for (String s : group) {
                System.out.println(s);
            }
        }
    }
}
