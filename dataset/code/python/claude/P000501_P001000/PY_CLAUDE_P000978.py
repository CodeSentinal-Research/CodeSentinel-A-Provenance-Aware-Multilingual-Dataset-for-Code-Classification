
import math
x1,y1=map(int,input().split());x2,y2=map(int,input().split());x3,y3=map(int,input().split())
a=math.dist((x2,y2),(x3,y3));b=math.dist((x1,y1),(x3,y3));c=math.dist((x1,y1),(x2,y2))
sides=sorted([a,b,c])
if abs(sides[0]**2+sides[1]**2-sides[2]**2)<1e-9: t='Right'
elif sides[0]==sides[1]==sides[2]: t='Equilateral'
elif sides[0]==sides[1] or sides[1]==sides[2]: t='Isosceles'
else: t='Scalene'
print(t)
