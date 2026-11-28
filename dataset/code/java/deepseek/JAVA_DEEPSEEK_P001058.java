import java.util.*;

public class Main {
    static class FreqStack {
        Stack<Integer> stack;
        HashMap<Integer, Integer> freqMap;
        HashMap<Integer, Stack<Integer>> groupMap;
        int maxFreq;

        public FreqStack() {
            stack = new Stack<>();
            freqMap = new HashMap<>();
            groupMap = new HashMap<>();
            maxFreq = 0;
        }

        public void push(int x) {
            int freq = freqMap.getOrDefault(x, 0) + 1;
            freqMap.put(x, freq);
            if (freq > maxFreq) {
                maxFreq = freq;
            }
            if (!groupMap.containsKey(freq)) {
                groupMap.put(freq, new Stack<>());
            }
            groupMap.get(freq).push(x);
            stack.push(x);
        }

        public int pop() {
            int x = stack.pop();
            int freq = freqMap.get(x);
            if (groupMap.get(freq).size() == 1) {
                groupMap.remove(freq);
                maxFreq--;
            } else {
                groupMap.get(freq).pop();
            }
            freqMap.put(x, freq - 1);
            return x;
        }
    }

    public static void main(String[] args) {
        FreqStack fs = new FreqStack();
        fs.push(5);
        fs.push(7);
        fs.push(5);
        fs.push(7);
        fs.push(4);
        fs.push(5);
        System.out.println(fs.pop()); // 5
        System.out.println(fs.pop()); // 7
        System.out.println(fs.pop()); // 5
        System.out.println(fs.pop()); // 4
    }
}
