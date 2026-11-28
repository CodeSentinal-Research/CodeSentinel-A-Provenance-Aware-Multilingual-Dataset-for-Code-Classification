# problem title : Search Books by Author and Genre
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
author=str(q.get('author','')); genre=str(q.get('genre',''))
for r in records:
    if str(r.get('author',''))==author and str(r.get('genre',''))==genre: out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
