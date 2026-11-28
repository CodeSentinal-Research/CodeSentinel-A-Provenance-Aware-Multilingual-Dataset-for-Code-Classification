
n=int(input())
def hanoi(n,f,t,a):
    if n==1: print(f'Move disk 1 from {f} to {t}');return
    hanoi(n-1,f,a,t);print(f'Move disk {n} from {f} to {t}');hanoi(n-1,a,t,f)
hanoi(n,'A','C','B')
