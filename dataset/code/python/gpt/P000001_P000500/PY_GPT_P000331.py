# problem title : Exclusive Time of Functions
# Stack start times and add durations to the function that ends.
n=int(input()); logs=[input() for _ in range(int(input()))]; ans=[0]*n; st=[]; prev=0
for log in logs:
    fid,typ,t=log.split(':'); fid=int(fid);t=int(t)
    if typ=='start':
        if st: ans[st[-1]]+=t-prev
        st.append(fid);prev=t
    else:
        ans[st.pop()]+=t-prev+1;prev=t+1
print(*ans)
