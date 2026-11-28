import java.io.*;
import java.util.*;

/**
 * Grammar.java
 * Reads a Context-Free Grammar (CFG) from a file and performs
 * Left Factoring and Left Recursion Removal (direct + indirect).
 *
 * File format:
 *   NonTerminal -> alt1 | alt2 | ...
 *   Non-terminals start with uppercase. Terminals are lowercase/symbols.
 *   Use "epsilon" or "@" for the empty string.
 */
public class Grammar {

    public static final String EPSILON = "epsilon";
    public static final String EOF     = "$";

    // Ordered list of non-terminals (preserves insertion order)
    private List<String> ntList;

    // Maps each non-terminal to its list of productions (each production = list of symbols)
    private Map<String, List<List<String>>> ruleMap;

    // First non-terminal encountered becomes the start symbol
    private String startNT;

    // Tracks suffix-counter per base name when generating fresh NT names
    private Map<String, Integer> suffixCount;

    // =========================================================================
    // CONSTRUCTOR
    // =========================================================================

    public Grammar() {
        ntList      = new ArrayList<>();
        ruleMap     = new LinkedHashMap<>();
        suffixCount = new HashMap<>();
    }

    // =========================================================================
    // FILE READING
    // =========================================================================

    /** Reads grammar rules from a file. Each line: NT -> body1 | body2 | ... */
    public void readFromFile(String path) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(path));
        String line;
        while ((line = reader.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;

            String[] halves = line.split("->", 2);
            if (halves.length != 2) {
                System.err.println("[WARNING] Skipping malformed line: " + line);
                continue;
            }

            String lhs = halves[0].trim();
            String rhs = halves[1].trim();

            if (lhs.isEmpty() || !Character.isUpperCase(lhs.charAt(0))) {
                System.err.println("[WARNING] Non-terminal must start with uppercase: '" + lhs + "'");
                continue;
            }

            if (!ruleMap.containsKey(lhs)) {
                ntList.add(lhs);
                ruleMap.put(lhs, new ArrayList<>());
            }

            for (String alt : rhs.split("\\|")) {
                alt = alt.trim();
                if (alt.isEmpty()) continue;
                List<String> body = new ArrayList<>();
                for (String tok : alt.split("\\s+")) {
                    if (tok.isEmpty()) continue;
                    body.add((tok.equalsIgnoreCase("epsilon") || tok.equals("@")) ? EPSILON : tok);
                }
                if (!body.isEmpty()) ruleMap.get(lhs).add(body);
            }
        }
        reader.close();

        if (ntList.isEmpty()) throw new IOException("No valid productions found in: " + path);
        startNT = ntList.get(0);
        System.out.println("[Grammar] Read " + ntList.size() + " non-terminal(s). Start = " + startNT);
    }

    // =========================================================================
    // LEFT FACTORING
    // =========================================================================

    /**
     * Repeatedly left-factors until no common prefixes remain.
     * Groups alternatives by first symbol; extracts shared prefixes into new NTs.
     */
    public void applyLeftFactoring() {
        boolean changed = true;
        int guard = 200;
        while (changed && guard-- > 0) {
            changed = false;
            for (String nt : new ArrayList<>(ntList)) {
                if (factorSingleNT(nt)) changed = true;
            }
        }
        System.out.println("[LeftFactoring] Complete.");
    }

    private boolean factorSingleNT(String nt) {
        List<List<String>> alts = ruleMap.get(nt);
        if (alts == null || alts.size() < 2) return false;

        Map<String, List<List<String>>> groups = new LinkedHashMap<>();
        for (List<String> alt : alts) {
            if (!alt.isEmpty()) {
                groups.computeIfAbsent(alt.get(0), k -> new ArrayList<>()).add(alt);
            }
        }

        for (List<List<String>> grp : groups.values()) {
            if (grp.size() < 2) continue;
            List<String> prefix = computeLCP(grp);
            if (prefix.isEmpty()) continue;

            String freshNT = makeFreshName(nt);
            ntList.add(freshNT);

            List<List<String>> suffixes = new ArrayList<>();
            for (List<String> alt : grp) {
                List<String> tail = new ArrayList<>(alt.subList(prefix.size(), alt.size()));
                if (tail.isEmpty()) tail.add(EPSILON);
                suffixes.add(tail);
            }
            ruleMap.put(freshNT, suffixes);

            alts.removeAll(grp);
            List<String> merged = new ArrayList<>(prefix);
            merged.add(freshNT);
            alts.add(merged);
            return true;
        }
        return false;
    }

    /** Returns the longest common prefix across a list of symbol sequences. */
    private List<String> computeLCP(List<List<String>> seqs) {
        if (seqs.isEmpty()) return new ArrayList<>();
        List<String> prefix = new ArrayList<>(seqs.get(0));
        for (int i = 1; i < seqs.size(); i++) {
            List<String> other = seqs.get(i);
            int len = 0;
            while (len < prefix.size() && len < other.size() && prefix.get(len).equals(other.get(len))) len++;
            prefix = prefix.subList(0, len);
            if (prefix.isEmpty()) break;
        }
        return new ArrayList<>(prefix);
    }

    // =========================================================================
    // LEFT RECURSION REMOVAL
    // =========================================================================

    /**
     * Removes direct and indirect left recursion using the standard Dragon Book algorithm.
     * Orders NTs, substitutes indirect recursion, then eliminates direct recursion.
     */
    public void removeLeftRecursion() {
        List<String> original = new ArrayList<>(ntList);
        int n = original.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                replaceIndirect(original.get(i), original.get(j));
            }
            eliminateDirect(original.get(i));
        }
        System.out.println("[LeftRecursion] Complete.");
    }

    /** Substitutes Ai -> Aj alpha with all expansions of Aj. */
    private void replaceIndirect(String ai, String aj) {
        List<List<String>> aiRules = ruleMap.get(ai);
        List<List<String>> ajRules = ruleMap.get(aj);
        if (aiRules == null || ajRules == null) return;

        List<List<String>> updated = new ArrayList<>();
        boolean didChange = false;

        for (List<String> prod : aiRules) {
            if (!prod.isEmpty() && prod.get(0).equals(aj)) {
                List<String> tail = prod.subList(1, prod.size());
                for (List<String> ajProd : ajRules) {
                    List<String> newProd = new ArrayList<>();
                    if (ajProd.size() == 1 && ajProd.get(0).equals(EPSILON)) {
                        newProd.addAll(tail.isEmpty() ? List.of(EPSILON) : tail);
                    } else {
                        newProd.addAll(ajProd);
                        newProd.addAll(tail);
                    }
                    updated.add(newProd);
                }
                didChange = true;
            } else {
                updated.add(prod);
            }
        }
        if (didChange) ruleMap.put(ai, updated);
    }

    /**
     * Eliminates direct left recursion from one NT.
     * A -> A a | b  becomes  A -> b A'  and  A' -> a A' | epsilon
     */
    private void eliminateDirect(String nt) {
        List<List<String>> rules = ruleMap.get(nt);
        if (rules == null) return;

        List<List<String>> recur    = new ArrayList<>();
        List<List<String>> nonRecur = new ArrayList<>();

        for (List<String> prod : rules) {
            (prod.isEmpty() || !prod.get(0).equals(nt) ? nonRecur : recur).add(prod);
        }
        if (recur.isEmpty()) return;

        String primeNT = makeFreshName(nt);
        ntList.add(primeNT);

        List<List<String>> ntNewRules = new ArrayList<>();
        if (nonRecur.isEmpty()) {
            ntNewRules.add(new ArrayList<>(List.of(primeNT)));
        } else {
            for (List<String> beta : nonRecur) {
                List<String> p = new ArrayList<>();
                if (beta.size() == 1 && beta.get(0).equals(EPSILON)) {
                    p.add(primeNT);
                } else {
                    p.addAll(beta);
                    p.add(primeNT);
                }
                ntNewRules.add(p);
            }
        }
        ruleMap.put(nt, ntNewRules);

        List<List<String>> primeRules = new ArrayList<>();
        for (List<String> rec : recur) {
            List<String> body = new ArrayList<>(rec.subList(1, rec.size()));
            body.add(primeNT);
            primeRules.add(body);
        }
        primeRules.add(new ArrayList<>(List.of(EPSILON)));
        ruleMap.put(primeNT, primeRules);
    }

    // =========================================================================
    // NAME GENERATION
    // =========================================================================

    /** Creates a unique Prime-suffixed name: ExprPrime, ExprPrime1, etc. */
    private String makeFreshName(String base) {
        String root = base.replaceAll("\\d+$", "");
        int idx = suffixCount.getOrDefault(root, 0);
        String candidate;
        do {
            candidate = (idx == 0) ? root + "Prime" : root + "Prime" + idx;
            idx++;
        } while (ruleMap.containsKey(candidate));
        suffixCount.put(root, idx);
        return candidate;
    }

    // =========================================================================
    // DISPLAY / OUTPUT
    // =========================================================================

    public void display(String heading) {
        System.out.println("\n============================== " + heading + " ==============================");
        for (String nt : ntList) {
            List<List<String>> alts = ruleMap.get(nt);
            if (alts == null) continue;
            StringBuilder sb = new StringBuilder(String.format("  %-20s -> ", nt));
            for (int i = 0; i < alts.size(); i++) {
                sb.append(String.join(" ", alts.get(i)));
                if (i < alts.size() - 1) sb.append("  |  ");
            }
            System.out.println(sb);
        }
        System.out.println();
    }

    public void writeToFile(String path, boolean append, String heading) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(path, append));
        if (heading != null) pw.println("=== " + heading + " ===");
        for (String nt : ntList) {
            List<List<String>> alts = ruleMap.get(nt);
            if (alts == null) continue;
            StringBuilder sb = new StringBuilder(nt + " -> ");
            for (int i = 0; i < alts.size(); i++) {
                sb.append(String.join(" ", alts.get(i)));
                if (i < alts.size() - 1) sb.append(" | ");
            }
            pw.println(sb);
        }
        pw.println();
        pw.close();
    }

    // =========================================================================
    // QUERIES
    // =========================================================================

    public boolean isNonTerminal(String sym) { return ruleMap.containsKey(sym); }

    public boolean isTerminal(String sym) {
        return !isNonTerminal(sym) && !sym.equals(EPSILON) && !sym.equals(EOF);
    }

    public Set<String> getAllTerminals() {
        Set<String> result = new LinkedHashSet<>();
        for (List<List<String>> alts : ruleMap.values())
            for (List<String> alt : alts)
                for (String sym : alt)
                    if (isTerminal(sym)) result.add(sym);
        return result;
    }

    // =========================================================================
    // GETTERS
    // =========================================================================

    public List<String> getNonTerminals()                   { return ntList; }
    public Map<String, List<List<String>>> getProductions() { return ruleMap; }
    public List<List<String>> getProductionsFor(String nt)  { return ruleMap.getOrDefault(nt, new ArrayList<>()); }
    public String getStartSymbol()                          { return startNT; }
}
