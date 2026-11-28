import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            List<Integer> st = new ArrayList<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("push")) {
                    st.add(scanner.nextInt());
                } else if (cmd.equals("pop")) {
                    if (!st.isEmpty()) {
                        System.out.println(st.remove(st.size() - 1));
                    }
                } else if (cmd.equals("top")) {
                    if (!st.isEmpty()) System.out.println(st.get(st.size() - 1));
                } else if (cmd.equals("empty")) {
                    System.out.println(st.isEmpty() ? "true" : "false");
                }
            }
        }
    }
}