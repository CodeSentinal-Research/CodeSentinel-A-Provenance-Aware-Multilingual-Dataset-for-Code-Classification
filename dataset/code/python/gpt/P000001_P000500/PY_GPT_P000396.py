# problem title : Search Active User Accounts
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
value=str(q.get('value',q.get('query','')))
for r in records:
    if str(r.get('active',''))==value: out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
