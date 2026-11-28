// Question: Find the first non-repeating character in a stream of characters using queue and frequency array.
// Example Test Case:
// Input: Stream = "a a b c"
// Output: Stream output = 'a', '#', 'b', 'b'

#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

void enqueue(char c) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = c;
}

void dequeue() {
    if (front == -1 || front > rear) return;
    front++;
}

char getFront() {
    if (front == -1 || front > rear) return '\0';
    return queue[front];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void firstNonRepeating(char *stream) {
    int i;
    int freq[26] = {0};
    front = rear = -1;

    printf("Stream: %s\n", stream);
    printf("First non-repeating at each point: ");

    for (i = 0; stream[i] != '\0'; i++) {
        char ch = stream[i];
        freq[ch - 'a']++;
        enqueue(ch);

        while (!isEmpty() && freq[getFront() - 'a'] > 1) {
            dequeue();
        }

        if (isEmpty())
            printf("-1 ");
        else
            printf("%c ", getFront());
    }
    printf("\n\n");
}

int main() {
    // Test cases
    firstNonRepeating("aabc");          // a -1 b b
    firstNonRepeating("aabccxb");       // a -1 b b b b x
    firstNonRepeating("aaaa");          // a -1 -1 -1
    firstNonRepeating("abcabc");        // a a a a a a
    firstNonRepeating("");              // (empty, no output)

    return 0;
}
