#RECURSION
count=0
def function():
    global count
    if count == 3:
        return
    print(count)
    count+=1
    function()
    
function()

# print name n times

def name(i,n):
    if i>n:
        return
    print("sowmya")
    name(i+1,n)
    
name(1,5)

# print linearly from 1 to n

def numbers(i,n):
    if i > n :
        return
    print(i)
    numbers(i+1,n)
numbers(1,int(input()))


#print N TO 1

def number(i,n):
    if n < i:
        return
    print(n)
    number(i,n-1)
number(1,10)

def numbers(i,n):
    if i < 1 :
        return
    print(i)
    numbers(i-1,n)
numbers(3,3)

# print 1 to N USING BACKTRACKING
def backtrack(i,n):
    if i<1:
        return
    backtrack(i-1,n)
    print(i)
    
backtrack(5,5)

# print n to 1 USING BACKTRACKING

def back(i,n):
    if i > n:
        return
    back(i+1,n)
    print(i)
    
n=3
back(1,n)

# sum of first n numbers using recursion
#parameterised

def sumation(i,total):
    if i < 1:
        print(total)
        return 
    sumation(i-1,total+i)
    
sumation(5,0)  
    
# functional

def sum(n):
    if n==0:
        return 0
    return n+sum(n-1)
print(sum(3))

#factorial
def factorial(n):
    if n==1:
        return 1
    elif n==0:
        return 0
    else:
        return n*factorial(n-1)
    
print(factorial(3))

#Reverse an array using recursion

def array(l, a, n):
    if l >= n:
        return 
    a[l], a[n] = a[n], a[l]
    array(l + 1, a, n - 1)
a = [2,3,4,5]   
array(0, a, len(a)-1)  
print("reverse array",a )   

#another way using single pointer
n=len(a)
def rev(i):
    if i>=n/2:
        return
    a[i], a[n - i - 1] = a[n - i - 1], a[i]
    rev(i + 1)
rev(0) 
print(a)   

#check string palindrom or not

def palindrom(i,s):
    if i >= n//2:
        print("palindrome")
        return
    if s[i] != s[n-i-1]:
        print(" not palindrome")
        
        return 
    palindrom(i+1,s)
s="spos"
n=len(s)
palindrom(0,s)

#fibnocci

def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)

n = 5
for i in range(n):
    print(fib(i), end=" ")