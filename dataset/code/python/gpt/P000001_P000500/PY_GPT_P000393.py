# problem title : Search Contacts by Name Prefix
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
prefix=str(q.get('prefix',q.get('value','')))
for r in records:
    if str(r.get('name','')).startswith(prefix): out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
