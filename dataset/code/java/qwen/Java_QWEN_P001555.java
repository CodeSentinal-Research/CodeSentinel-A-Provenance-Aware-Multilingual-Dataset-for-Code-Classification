import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        
        int maxVowels = 0;
        int currVowels = 0;
        String vowels = "aeiou";
        
        for(int i=0; i<k; i++) {
            if(vowels.indexOf(s.charAt(i)) != -1) currVowels++;
        }
        maxVowels = currVowels;
        
        for(int i=k; i<s.length(); i++) {
            if(vowels.indexOf(s.charAt(i)) != -1) currVowels++;
            if(vowels.indexOf(s.charAt(i-k)) != -1) currVowels--;
            maxVowels = Math.max(maxVowels, currVowels);
        }
        System.out.println(maxVowels);
    }
}
