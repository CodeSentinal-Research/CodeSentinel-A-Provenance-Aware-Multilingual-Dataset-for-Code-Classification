# problem title : Longest Uncommon Subsequence
# If the strings differ, the longer string itself is an uncommon subsequence.
a=input();b=input();print(-1 if a==b else max(len(a),len(b)))
