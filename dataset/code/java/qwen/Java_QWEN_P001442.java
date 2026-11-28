import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] paths = new String[n];
        for(int i=0; i<n; i++) paths[i] = sc.nextLine();
        
        Map<String, List<String>> contentMap = new HashMap<>();
        for(String path : paths) {
            String[] parts = path.split(" ");
            String dir = parts[0];
            for(int i=1; i<parts.length; i++) {
                String file = parts[i];
                int idx = file.indexOf('(');
                String name = file.substring(0, idx);
                String content = file.substring(idx + 1, file.length() - 1);
                contentMap.computeIfAbsent(content, k -> new ArrayList<>()).add(dir + "/" + name);
            }
        }
        
        for(List<String> group : contentMap.values()) {
            if(group.size() > 1) {
                System.out.println(group);
            }
        }
    }
}
