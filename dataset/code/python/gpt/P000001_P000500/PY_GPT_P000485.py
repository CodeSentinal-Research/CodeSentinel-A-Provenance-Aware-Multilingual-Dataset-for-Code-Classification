# problem title : Asteroid Collision
# A stack models collisions: a right-moving asteroid can collide only with a left-moving one.
st=[]
for x in map(int,input().split()):
 alive=True
 while alive and x<0 and st and st[-1]>0:
  if st[-1]<-x:st.pop();continue
  if st[-1]==-x:st.pop()
  alive=False
 if alive:st.append(x)
print(*st)
