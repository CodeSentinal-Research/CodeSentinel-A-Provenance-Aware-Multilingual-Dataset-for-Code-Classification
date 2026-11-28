import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();
        String broken = sc.next();
        Set<Character> brokenSet = new HashSet<>();
        for (char c : broken.toCharArray()) brokenSet.add(c);
        
        String[] words = text.split(" ");
        int count = 0;
        for (String w : words) {
            boolean canType = true;
            for (char c : w.toCharArray()) {
                if (brokenSet.contains(c)) {
                    canType = false; break;
                }
            }
            if (canType) count++;
        }
        System.out.println(count);
    }
}
