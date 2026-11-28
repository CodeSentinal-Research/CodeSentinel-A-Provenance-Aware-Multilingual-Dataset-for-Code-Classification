# problem title : Find Element in Array
# Linear search checks each value against the target.
n=int(input());a=list(map(int,input().split()));x=int(input());print("Found" if x in a else "Not Found")
