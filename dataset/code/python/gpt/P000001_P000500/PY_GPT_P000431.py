# problem title : Count Occurrences using Linear Search
# Count target occurrences in one pass as a linear-search exercise.
n,t=map(int,input().split());a=list(map(int,input().split()));print(sum(x==t for x in a))
