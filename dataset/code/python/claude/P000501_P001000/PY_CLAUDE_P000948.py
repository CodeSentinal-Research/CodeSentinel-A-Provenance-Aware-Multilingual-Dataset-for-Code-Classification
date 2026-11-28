
n=int(input());x,y=map(int,input().split())
from functools import lru_cache
@lru_cache(None)
def win(x,y):
    moves=[(x+1,y+2),(x+2,y+1),(x+1,y-2),(x+2,y-1),(x-1,y+2),(x-2,y+1),(x-1,y-2),(x-2,y-1)]
    return any(1<=nx<=n and 1<=ny<=n and not win(nx,ny) for nx,ny in moves)
print('First' if win(x,y) else 'Second')
