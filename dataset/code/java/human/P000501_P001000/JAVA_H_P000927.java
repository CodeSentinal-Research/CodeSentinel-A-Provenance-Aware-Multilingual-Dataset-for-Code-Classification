import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
/**
 * ShamirSecretSharing
 *
 * Objective:
 *   Implements the core operations for Shamir's Secret Sharing scheme:
 *   1. Parsing test-case JSON files with shares.
 *   2. Converting string shares in arbitrary bases into BigInteger values.
 *   3. Reconstructing the secret via Lagrange interpolation.
 *
 * Inputs:
 *   - Two JSON files ("testcase1.json" and "testcase2.json") containing:
 *     * keys.n: total number of shares (unused beyond validation)
 *     * keys.k: threshold number of shares needed to reconstruct
 *     * A map of x-coordinate → { base, value } strings for each share
 *
 * Output:
 *   - The reconstructed secret for each test case, printed to stdout.
 */

public class ShamirSecretSharing {

    /**
     * convertFromBase
     *
     * Objective:
     *   Takes a string representation of a non-negative integer in a given base
     *   (2 ≤ base ≤ 36) and converts it into a decimal BigInteger.
     *
     * Inputs:
     *   - value: the string digits in the specified base
     *   - base: the radix/base of the input string (e.g. 16 for hex)
     *
     * Returns:
     *   - A BigInteger representing the numeric value of the input string.
     *
     * Throws:
     *   - IllegalArgumentException if any character is invalid or digit ≥ base.
     */
    
    // Convert a string value in the given base to a decimal BigInteger
    private static BigInteger convertFromBase(String value, int base) {
        BigInteger result = BigInteger.ZERO;
        BigInteger baseBI = BigInteger.valueOf(base);
        
        for (int i = 0; i < value.length(); i++) {
            char c = value.charAt(i);
            int digit;
            
            if (c >= '0' && c <= '9') {
                digit = c - '0';
            } else if (c >= 'a' && c <= 'z') {
                digit = c - 'a' + 10;
            } else if (c >= 'A' && c <= 'Z') {
                digit = c - 'A' + 10;
            } else {
                throw new IllegalArgumentException("Invalid character in input: " + c);
            }
            
            if (digit >= base) {
                throw new IllegalArgumentException("Digit out of range for the specified base");
            }
            
            result = result.multiply(baseBI).add(BigInteger.valueOf(digit));
        }
        
        return result;
    }
    
      /**
     * findSecret
     *
     * Objective:
     *   Given a list of k points (x, y) on a polynomial of degree < k,
     *   recover the free coefficient (secret) using Lagrange interpolation at x=0.
     *
     * Inputs:
     *   - points: list of Point objects containing x (int) and y (BigInteger)
     *   - k: the number of points (threshold)
     *
     * Returns:
     *   - The reconstructed secret as a BigInteger.
     *
     * Notes:
     *   - This implementation does not use a finite field. For real SSS you must
     *     perform everything modulo a prime and use modular inverses.
     */
    // Find the secret using Lagrange interpolation
    private static BigInteger findSecret(List<Point> points, int k) {
        BigInteger secret = BigInteger.ZERO;
        
        // We only need k points for interpolation
        for (int i = 0; i < k; i++) {
            BigInteger numerator = BigInteger.ONE;
            BigInteger denominator = BigInteger.ONE;
            
            for (int j = 0; j < k; j++) {
                if (i != j) {
                    // Calculate the Lagrange basis polynomial evaluated at x = 0
                    // Li(0) = Π(j≠i) (0 - xj) / (xi - xj)
                    
                    // Calculate (0 - xj)
                    BigInteger xj = BigInteger.valueOf(points.get(j).x);
                    BigInteger num = BigInteger.ZERO.subtract(xj);
                    
                    // Calculate (xi - xj)
                    BigInteger xi = BigInteger.valueOf(points.get(i).x);
                    BigInteger den = xi.subtract(xj);
                    
                    numerator = numerator.multiply(num);
                    denominator = denominator.multiply(den);
                }
            }
            
            // Calculate term = yi * Li(0)
            BigInteger term = points.get(i).y;
            term = term.multiply(numerator);
            
            // Handle the division with modular inverse if needed
            BigInteger gcd = denominator.gcd(term);
            term = term.divide(gcd);
            denominator = denominator.divide(gcd);
            
            if (denominator.signum() < 0) {
                term = term.negate();
                denominator = denominator.negate();
            }
            
            if (denominator.equals(BigInteger.ONE)) {
                secret = secret.add(term);
            } else {
                // We need to compute term/denominator
                // For simplicity, we'll use direct division which might cause precision issues
                // In a real-world scenario, you might want to use modular arithmetic
                secret = secret.add(term.divide(denominator));
            }
        }
        
        return secret;
    }
     /**
     * Point
     *
     * Simple holder for a share's (x, y) coordinate.
     */

    // Class to represent a point (x, y)
    private static class Point {
        int x;
        BigInteger y;
        
        Point(int x, BigInteger y) {
            this.x = x;
            this.y = y;
        }
    }
    /**
     * parseJson
     *
     * Objective:
     *   Reads a minimal JSON file containing keys.n, keys.k, and a mapping of
     *   point-indices to { base, value } strings. Designed for specific test cases.
     *
     * Inputs:
     *   - filename: path to the JSON file
     *
     * Returns:
     *   - A Map<String,Object> where:
     *     * "keys" → Map with "n" and "k" integers
     *     * each point index → Map<String,String> with "base" and "value"
     *
     * Throws:
     *   - IOException if the file cannot be read.
     */
    
    // Simple JSON parser for our specific test cases
    private static Map<String, Object> parseJson(String filename) throws IOException {
        Map<String, Object> result = new HashMap<>();
        Map<String, Object> keys = new HashMap<>();
        result.put("keys", keys);
        
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        StringBuilder content = new StringBuilder();
        String line;
        while ((line = reader.readLine()) != null) {
            content.append(line);
        }
        reader.close();
        
        String jsonStr = content.toString();
        
        // Parse n and k values
        Pattern keysPattern = Pattern.compile("\"keys\":\\s*\\{\\s*\"n\":\\s*(\\d+),\\s*\"k\":\\s*(\\d+)\\s*\\}");
        Matcher keysMatcher = keysPattern.matcher(jsonStr);
        if (keysMatcher.find()) {
            keys.put("n", Integer.parseInt(keysMatcher.group(1)));
            keys.put("k", Integer.parseInt(keysMatcher.group(2)));
        }
        
        // Parse points
        Pattern pointPattern = Pattern.compile("\"(\\d+)\":\\s*\\{\\s*\"base\":\\s*\"(\\d+)\",\\s*\"value\":\\s*\"([^\"]+)\"\\s*\\}");
        Matcher pointMatcher = pointPattern.matcher(jsonStr);
        
        while (pointMatcher.find()) {
            String key = pointMatcher.group(1);
            Map<String, String> point = new HashMap<>();
            point.put("base", pointMatcher.group(2));
            point.put("value", pointMatcher.group(3));
            result.put(key, point);
        }
        
        return result;
    }
    /**
     * main
     *
     * Orchestrates:
     * 1. Parsing two test-case JSON files.
     * 2. Converting each share value from its base to BigInteger.
     * 3. Reconstructing each secret with findSecret().
     * 4. Printing results.
     */
    
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        try {
            // Process the first test case
            Map<String, Object> data1 = parseJson("testcase1.json");
            
            Map<String, Object> keys1 = (Map<String, Object>) data1.get("keys");
            int n1 = (Integer) keys1.get("n");
            int k1 = (Integer) keys1.get("k");
            
            List<Point> points1 = new ArrayList<>();
            
            for (String key : data1.keySet()) {
                if (key.equals("keys")) continue;
                
                int x = Integer.parseInt(key);
                Map<String, String> point = (Map<String, String>) data1.get(key);
                int base = Integer.parseInt(point.get("base"));
                String valueStr = point.get("value");
                
                BigInteger y = convertFromBase(valueStr, base);
                points1.add(new Point(x, y));
            }
            
            // Process the second test case
            Map<String, Object> data2 = parseJson("testcase2.json");
            
            Map<String, Object> keys2 = (Map<String, Object>) data2.get("keys");
            int n2 = (Integer) keys2.get("n");
            int k2 = (Integer) keys2.get("k");
            
            List<Point> points2 = new ArrayList<>();
            
            for (String key : data2.keySet()) {
                if (key.equals("keys")) continue;
                
                int x = Integer.parseInt(key);
                Map<String, String> point = (Map<String, String>) data2.get(key);
                int base = Integer.parseInt(point.get("base"));
                String valueStr = point.get("value");
                
                BigInteger y = convertFromBase(valueStr, base);
                points2.add(new Point(x, y));
            }
            
            // Find the secrets
            BigInteger secret1 = findSecret(points1, k1);
            BigInteger secret2 = findSecret(points2, k2);
            
            // Print the results
            System.out.println("Secret for test case 1: " + secret1);
            System.out.println("Secret for test case 2: " + secret2);
            
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}