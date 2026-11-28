Here is a Python code using Linked List to solve the given problem.

class Node:
    def __init__(self, coef, exp, next=None):
        self.coef = coef
        self.exp = exp
        self.next = next

class Polynomial:
    def __init__(self):
        self.head = None

    def insert(self, coef, exp):
        if not self.head or self.head.exp < exp:
            self.head = Node(coef, exp, self.head)
        else:
            cur = self.head
            while cur.next and cur.next.exp >= exp:
                cur = cur.next
            cur.next = Node(coef, exp, cur.next)

    def delete(self, exp):
        if self.head and self.head.exp == exp:
            self.head = self.head.next
        else:
            cur = self.head
            while cur and cur.next:
                if cur.next.exp == exp:
                    cur.next = cur.next.next
                cur = cur.next

    def evaluate(self, x):
        cur = self.head
        res = 0
        while cur:
            res += cur.coef * (x ** cur.exp)
            cur = cur.next
        return res

    def display(self):
        cur = self.head
        while cur:
            print(f'{cur.coef}x^{cur.exp}', end=' ')
            cur = cur.next and ' + ' or ''
        print()

Here is a main function that handles the input and calls the appropriate methods:

def main():
    poly = Polynomial()
    while True:
        cmd = input()
        if cmd[0] == 'i':
            coef, exp = map(int, cmd[2:].split())
            poly.insert(coef, exp)
        elif cmd[0] == 'd':
            exp = int(cmd[2:])
            poly.delete(exp)
        elif cmd[0] == 'e':
            x = int(cmd[2:])
            res = poly.evaluate(x)
            print(f'Evaluate result: {res}')
        elif cmd[0] == 's':
            poly.display()
        elif cmd[0] == 'q':
            break
        else:
            print('Invalid command')

if __name__ == '__main__':
    main()

This code first creates a Polynomial object. Then, it enters an infinite loop where it reads a command from the input. If the command starts with 'i', it inserts a term into the polynomial with the given coefficient and exponent. If the command starts with 'd', it deletes a term with the given exponent. If the command starts with 'e', it evaluates the polynomial for the given value of x. If the command starts with 's', it displays the polynomial. If the command starts with 'q', it quits the program. Otherwise, it prints an error message.