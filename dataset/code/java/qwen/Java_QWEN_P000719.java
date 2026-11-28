import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        restoreIP(s, 0, new ArrayList<>());
    }
    static void restoreIP(String s, int idx, List<String> parts) {
        if(parts.size() == 4 && idx == s.length()) {
            System.out.println(String.join(".", parts));
            return;
        }
        if(parts.size() >= 4 || idx >= s.length()) return;
        for(int i=1; i<=3; i++) {
            if(idx + i > s.length()) break;
            String part = s.substring(idx, idx + i);
            if((part.length() > 1 && part.startsWith("0")) || Integer.parseInt(part) > 255) continue;
            parts.add(part);
            restoreIP(s, idx + i, parts);
            parts.remove(parts.size() - 1);
        }
    }
}
