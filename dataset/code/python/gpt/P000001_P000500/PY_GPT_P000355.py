# problem title : Find Missing Value in Search List
# Membership in the array decides whether the target is missing.
n=int(input());a=list(map(int,input().split()));x=int(input());print("Present" if x in set(a) else "Missing")
