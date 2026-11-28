import sys

def solve():
    expr = sys.stdin.readline().strip()
    
    def compute(expr):
        if expr.isdigit():
            return [int(expr)]
            
        results = []
        for i in range(len(expr)):
            if expr[i] in '+-*':
                left_results = compute(expr[:i])
                right_results = compute(expr[i+1:])
                
                for l in left_results:
                    for r in right_results:
                        if expr[i] == '+':
                            results.append(l + r)
                        elif expr[i] == '-':
                            results.append(l - r)
                        elif expr[i] == '*':
                            results.append(l * r)
        return results
        
    print(*sorted(compute(expr)))

if __name__ == "__main__":
    solve()

