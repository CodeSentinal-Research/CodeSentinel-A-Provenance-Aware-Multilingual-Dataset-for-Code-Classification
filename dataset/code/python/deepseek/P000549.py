Here is a Python solution for the problem. The main idea is to use a stack and a queue to simulate the process. We first put all elements of the input into the stack. Then we pop elements from the stack and enqueue them into the queue. We check if the popped element is in the output array. If it is, we remove it from the output array. If not, we return false immediately. If the end of the output array is reached, we return true.

def validate_stack_permutation(n, input, output):
    stack = []
    queue = []

    for i in range(n):
        stack.append(input[i])

    for i in range(n):
        while stack and stack[-1] != output[i]:
            element = stack.pop()
            queue.append(element)

        if not stack and queue:
            return False

        if stack and queue:
            stack.pop()
            queue.popleft()

    return True

In this code, we assume that the input and output are provided as lists in Python. The function `validate_stack_permutation` takes these as input and returns a boolean indicating whether the output sequence can be obtained from the input sequence using a single stack.

Here is a main function that can be used to test this solution:

def main():
    n = 3
    input_array = [1, 2, 3]
    output_array = [2, 3, 1]
    result = validate_stack_permutation(n, input_array, output_array)
    print(result)

if __name__ == "__main__":
    main()

This will print `True` if the output sequence can be obtained from the input sequence using a single stack, and `False` otherwise.