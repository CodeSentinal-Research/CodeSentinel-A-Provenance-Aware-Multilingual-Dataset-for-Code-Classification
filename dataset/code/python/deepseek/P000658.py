class BrowserHistory:
    def __init__(self, homepage):
        self.history = [homepage]
        self.index = 0

    def visit(self, windowId, url):
        self.history.insert(self.index + 1, url)
        self.index += 1

    def back(self, windowId, steps):
        self.index = max(0, self.index - steps)

    def forward(self, windowId, steps):
        self.index = min(len(self.history) - 1, self.index + steps)

    def newWindow(self, homepage):
        self.history.append(homepage)
        self.index += 1

    def closeWindow(self, windowId):
        self.history = self.history[:-1]

    def currentPage(self, windowId):
        return self.history[self.index]

def main():
    browser_history = BrowserHistory("www.google.com")
    browser_history.visit(0, "www.stackoverflow.com")
    browser_history.visit(0, "www.github.com")
    print(browser_history.currentPage(0))  
    browser_history.back(0, 1)
    print(browser_history.currentPage(0))  
    browser_history.forward(0, 1)
    print(browser_history.currentPage(0))  
    browser_history.newWindow("www.mozilla.org")
    print(browser_history.currentPage(0))  
    browser_history.closeWindow(0)
    print(browser_history.currentPage(0))  

if __name__ == "__main__":
    main()