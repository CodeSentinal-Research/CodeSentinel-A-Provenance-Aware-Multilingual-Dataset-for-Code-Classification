import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    r = int(input_data[idx]); idx += 1
    c = int(input_data[idx]); idx += 1
    
    h_cuts = list(map(int, input_data[idx:idx+r-1])); idx += r-1
    v_cuts = list(map(int, input_data[idx:idx+c-1])); idx += c-1
    
    h_cuts.sort(reverse=True)
    v_cuts.sort(reverse=True)
    
    h_ptr = 0
    v_ptr = 0
    h_pieces = 1
    v_pieces = 1
    cost = 0
    
    while h_ptr < len(h_cuts) and v_ptr < len(v_cuts):
        if h_cuts[h_ptr] > v_cuts[v_ptr]:
            cost += h_cuts[h_ptr] * v_pieces
            h_ptr += 1
            h_pieces += 1
        else:
            cost += v_cuts[v_ptr] * h_pieces
            v_ptr += 1
            v_pieces += 1
            
    while h_ptr < len(h_cuts):
        cost += h_cuts[h_ptr] * v_pieces
        h_ptr += 1
        
    while v_ptr < len(v_cuts):
        cost += v_cuts[v_ptr] * h_pieces
        v_ptr += 1
        
    print(cost)

if __name__ == "__main__":
    solve()

