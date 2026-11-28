import java.util.*;
import java.util.regex.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        List<String> ops = new ArrayList<>();
        while (scanner.hasNext()) {
            String token = scanner.next();
            if (token.equals("next()") || token.equals("hasNext()")) {
                ops.add(token);
            } else {
                sb.append(token).append(" ");
            }
        }
        List<Integer> nums = new ArrayList<>();
        Matcher m = Pattern.compile("-?\\d+").matcher(sb.toString());
        while (m.find()) nums.add(Integer.parseInt(m.group()));
        int idx = 0;
        for (String op : ops) {
            if (op.equals("next()")) {
                if (idx < nums.size()) System.out.println(nums.get(idx++));
            } else if (op.equals("hasNext()")) {
                System.out.println(idx < nums.size() ? "true" : "false");
            }
        }
    }
}