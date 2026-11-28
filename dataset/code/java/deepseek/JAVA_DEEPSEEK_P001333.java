import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String num = scanner.next();
        int target = scanner.nextInt();
        List<String> res = new ArrayList<>();
        backtrack(num, target, 0, 0, "", res);
        Collections.sort(res);
        for (String s : res) {
            System.out.println(s);
        }
    }

    private static void backtrack(String num, int target, long curr, long prev, String str, List<String> res) {
        if (str.length() == num.length() + 2) {
            if (curr == target) {
                res.add(str);
            }
            return;
        }
        for (int i = 0; i < num.length(); i++) {
            long currNum = Character.getNumericValue(num.charAt(i));
            if (str.length() == 0 && currNum == 0) {
                continue;
            }
            if (str.length() == 0 && num.charAt(0) == '0') {
                backtrack(num.substring(1), target, currNum, currNum, str + currNum, res);
            } else {
                backtrack(num, target, curr + currNum, currNum, str + "+" + currNum, res);
                backtrack(num, target, curr - currNum, -currNum, str + "-" + currNum, res);
                backtrack(num, target, curr - prev + currNum, prev - currNum, str + "*" + currNum, res);
            }
        }
    }
}
