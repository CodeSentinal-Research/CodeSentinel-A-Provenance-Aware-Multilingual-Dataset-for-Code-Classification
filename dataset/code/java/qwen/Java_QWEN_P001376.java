import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] strs = new String[n];
        for(int i=0; i<n; i++) strs[i] = sc.next();
        
        Map<String, List<String>> map = new TreeMap<>();
        for(String s : strs) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(s);
        }
        
        for(List<String> group : map.values()) {
            Collections.sort(group);
            System.out.println(group);
        }
    }
}
