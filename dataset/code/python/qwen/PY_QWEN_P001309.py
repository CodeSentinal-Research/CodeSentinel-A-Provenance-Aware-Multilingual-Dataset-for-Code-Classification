import sys
import math

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    s = int(input_data[0])
    n = int(input_data[1])
    m = int(input_data[1]) # Assuming M is daily requirement based on standard problem, but input says N is max purchase, M is daily req? 
    # Re-reading: "N is the maximum units purchasable per day and M is the daily food requirement."
    # Wait, input description: "First line contains integers S, N, and M".
    # Let's assume standard variable names: S=days, N=max_buy, M=daily_req.
    
    # Correction from prompt: "First line contains integers S, N, and M, where N is the maximum units purchasable per day and M is the daily food requirement."
    # Actually, usually it's S days, N max buy, M daily need.
    
    s_days = int(input_data[0])
    max_buy = int(input_data[1])
    daily_need = int(input_data[2])
    
    if daily_need > max_buy and s_days > 1:
        # If we can't buy enough for one day, and we need more than 1 day, impossible?
        # No, we can buy on multiple days.
        # But if daily_need > max_buy, we can never survive a single day if we start with 0.
        # Problem implies we start with 0 food.
        if daily_need > max_buy:
             print(-1)
             return
             
    # Total food needed
    total_needed = s_days * daily_need
    
    # Max food we can buy in one day is max_buy.
    # We can only buy on certain days? "Food can only be purchased on certain days" -> Usually means every day except Sunday or similar.
    # Prompt doesn't specify which days. "Food can only be purchased on certain days" is vague.
    # Standard version: Can buy every day except Sunday (every 7th day).
    # Let's assume we can buy every day for now unless specified.
    # If we can buy every day, min days = ceil(total_needed / max_buy).
    
    # However, "Survival on an Island" usually has a constraint like "Shop is closed on Sundays".
    # Without that specific constraint in the text provided, I will assume we can buy every day.
    # If we can buy every day:
    min_days = math.ceil(total_needed / max_buy)
    
    if min_days > s_days:
        print(-1)
    else:
        print(min_days)

if __name__ == "__main__":
    solve()

