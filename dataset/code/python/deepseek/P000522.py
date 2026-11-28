Here is a Python solution using a deque data structure for the browser history. 

from collections import deque

class BrowserHistory:

    def __init__(self, homepage): :
        self.history = deque([homepage])
        self.forward_history = deque()
        self.back_history = deque()

    def visit(self, url):
        self.history.append(url)
        self.back_history.clear()
        self.forward_history.append(url)

    def back(self, steps):
        for _ in range(steps):
            if self.back_history:
                self.forward_history.appendleft(self.back_history.pop())
                url = self.back_history.pop()
                self.history.append(url)
            else:
                break

    def forward(self, steps):
        for _ in range(steps):
            if self.forward_history:
                self.back_history.appendleft(self.forward_history.pop())
                url = self.forward_history.pop()
                self.history.append(url)
            else:
                break

    def print_current_page(self):
        print(self.history[-1])

def main():
    browser_history = BrowserHistory('homepage')
    operations = ['visit:google', 'visit:amazon', 'back:2', 'forward:3', 'back:1', 'forward:1', 'back:1', 'print_current_page']
    for op in operations:
        if op.startswith('visit:'):
            _, url = op.split(':')
            browser_history.visit(url)
        elif op.startswith('back:'):
            _, steps = op.split(':')
            browser_history.back(int(steps))
        elif op.startswith('forward:'):
            _, steps = op.split(':')
            browser_history.forward(int(steps))
        elif op == 'print_current_page':
            browser_history.print_current_page()

if __name__ == "__main__":
    main()

This solution uses a BrowserHistory class that encapsulates the browser's history as a deque. The visit method adds a new URL to the history. The back method moves the browser back by a given number of steps, removing URLs from the history. The forward method moves the browser forward by a given number of steps, adding URLs to the history. The print_current_page method prints the current URL. The main function demonstrates these operations on a browser history.