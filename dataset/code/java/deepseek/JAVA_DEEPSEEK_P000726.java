import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String expression = scanner.next();
        List<String> result = new ArrayList<>();
        generateAllExpressions(expression, 0, result);
        Collections.sort(result);
        for (String s : result) {
            System.out.println(s);
        }
    }

    private static void generateAllExpressions(String expression, int start, List<String> result) {
        if (start >= expression.length()) {
            result.add(expression);
            return;
        }
        for (int i = start; i < expression.length(); i++) {
            if (Character.isDigit(expression.charAt(i))) {
                continue;
           
            }
            for (int j = i + 2; j <= expression.length(); j++) {
                String newExpression = expression.substring(0, i) + "(" + expression.substring(i, j) + ")" + expression.substring(j);
                generateAllExpressions(newExpression, i + 4, result);
            }
        }
    }
}
