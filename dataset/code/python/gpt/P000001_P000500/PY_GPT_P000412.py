# problem title : Case-Insensitive Contact Search
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
name=str(q.get('name',q.get('query',''))).casefold()
for r in records:
    if str(r.get('name','')).casefold()==name: out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
