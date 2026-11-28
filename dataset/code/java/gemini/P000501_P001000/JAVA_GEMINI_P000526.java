import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String formula = scanner.next();
            Stack<Map<String, Integer>> st = new Stack<>();
            st.push(new TreeMap<>());
            int i = 0, n = formula.length();
            while (i < n) {
                if (formula.charAt(i) == '(') {
                    st.push(new TreeMap<>());
                    i++;
                } else if (formula.charAt(i) == ')') {
                    i++;
                    int iStart = i;
                    while (i < n && Character.isDigit(formula.charAt(i))) i++;
                    int mult = (iStart == i) ? 1 : Integer.parseInt(formula.substring(iStart, i));
                    Map<String, Integer> top = st.pop();
                    for (Map.Entry<String, Integer> entry : top.entrySet()) {
                        st.peek().put(entry.getKey(), st.peek().getOrDefault(entry.getKey(), 0) + entry.getValue() * mult);
                    }
                } else {
                    int iStart = i++;
                    while (i < n && Character.isLowerCase(formula.charAt(i))) i++;
                    String atom = formula.substring(iStart, i);
                    iStart = i;
                    while (i < n && Character.isDigit(formula.charAt(i))) i++;
                    int cnt = (iStart == i) ? 1 : Integer.parseInt(formula.substring(iStart, i));
                    st.peek().put(atom, st.peek().getOrDefault(atom, 0) + cnt);
                }
            }
            StringBuilder sb = new StringBuilder();
            for (Map.Entry<String, Integer> entry : st.peek().entrySet()) {
                sb.append(entry.getKey()).append(entry.getValue() > 1 ? entry.getValue() : "");
            }
            System.out.println(sb.toString());
        }
    }
}