import java.util.*;

public class Main {
    int i;
    String formula;

    public Main(String formula) {
        this.formula = formula;
        i = 0;
    }

    public String countOfAtoms() {
        Map<String, Integer> count = new TreeMap<>();
        while (i < formula.length()) {
            if (formula.charAt(i) == '(') {
                i++;
                for (Map.Entry<String, Integer> entry : countAtoms().entrySet()) {
                    count.put(entry.getKey(), count.getOrDefault(entry.getKey(), 0) + entry.getValue());
                }
            } else if (formula.charAt(i) == ')') {
                i++;
                break;
            } else {
                String atom = getAtom();
                count.put(atom, count.getOrDefault(atom, 0) + getCount());
            }
        }

        int multiplicity = getCount();
        for (String atom : count.keySet()) {
            count.put(atom, count.get(atom) * multiplicity);
        }

        StringBuilder sb = new StringBuilder();
        for (Map.Entry<String, Integer> entry : count.entrySet()) {
            sb.append(entry.getKey());
            if (entry.getValue() > 1) {
                sb.append(entry.getValue());
            }
        }
        return sb.toString();
    }

    private Map<String, Integer> countAtoms() {
        Map<String, Integer> count = new TreeMap<>();
        while (i < formula.length() && formula.charAt(i) != ')') {
            if (formula.charAt(i) == '(') {
                i++;
                for (Map.Entry<String, Integer> entry : countAtoms().entrySet()) {
                    count.put(entry.getKey(), count.getOrDefault(entry.getKey(), 0) + entry.getValue());
                }
            } else {
                String atom = getAtom();
                count.put(atom, count.getOrDefault(atom, 0) + getCount());
            }
        }
        return count;
    }

    private String getAtom() {
        StringBuilder sb = new StringBuilder();
        while (i < formula.length() && Character.isLowerCase(formula.charAt(i))) {
            sb.append(formula.charAt(i++));
        }
        return sb.toString();
    }

    private int getCount() {
        int count = 0;
        while (i < formula.length() && Character.isDigit(formula.charAt(i))) {
            count = count * 10 + (formula.charAt(i++) - '0');
        }
        return count == 0 ? 1 : count;
    }

    public static void main(String[] args) {
        Main main = new Main("H2O");
        System.out.println(main.countOfAtoms());
    }
}
