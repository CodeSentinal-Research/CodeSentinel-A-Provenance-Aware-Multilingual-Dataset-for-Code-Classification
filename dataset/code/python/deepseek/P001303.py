def max_capital():
    N, K, InitialCapital = map(int, input().split())
    projects = [list(map(int, input().split())) for _ in range(N)]
    
    projects.sort(key=lambda x: x[1], reverse=True)
    max_capital = InitialCapital
    
    for required_investment, expected_profit in projects[:K]:
        if max_capital >= required_investment:
            max_capital += expected_profit
        else:
            break
    
    print(max_capital)

max_capital()