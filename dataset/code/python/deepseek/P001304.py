def min_cost(R, C, horizontal_cut_costs, vertical_cut_costs):
    total_horizontal_cut_cost = sum(horizontal_cut_costs)
    
    total_vertical_cut_cost = sum(vertical_cut_costs)
    
    return min(total_horizontal_cut_cost, total_vertical_cut_cost)

def main():
    R, C = map(int, input().split())
    
    horizontal_cut_costs = list(map(int, input().split()))
    
    vertical_cut_costs = list(map(int, input().split()))
    
    print(min_cost(R, C, horizontal_cut_costs, vertical_cut_costs))

main()