import java.util.*;

public class Main {
    static class Equation {
        String var1;
        String var2;
        double value;

        public Equation(String var1, String var2, double value) {
            this.var1 = var1;
            this.var2 = var2;
            this.value = value;
        }
    }

    static Map<String, Double> map = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int E = scanner.nextInt();
        List<Equation> equations = new ArrayList<>();
        for (int i = 0; i < E; i++) {
            String var1 = scanner.next();
            String var2 = scanner.next();
            double value = scanner.nextDouble();
            equations.add(new Equation(var1, var2, value));
        }
        int Q = scanner.nextInt();
        for (int i = 0; i < Q; i++) {
            String var1 = scanner.next();
            String var2 = scanner.next();
            double result = solve(var1, var2);
            System.out.println(result == -1.0 ? -1.0 : String.format("%.1f", result));
        }
    }

    private static double solve(String var1, String var2) {
        if (!map.containsKey(var1)) {
            map.put(var1, 0.0);
        }
        if (!map.containsKey(var2)) {
            map.put(var2, 0.0);
        }
        if (map.get(var1) == 0.0 && map.get(var2) == 0.0) {
            return -1.0;
        }
        double result = map.get(var2) / map.get(var1);
        map.put(var1, result);
        map.put(var2, 0.0);
        return result;
    }
}
