# problem title : Search Products by Name Suffix
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
suffix=str(q.get('suffix',q.get('value','')))
for r in records:
    if str(r.get('name','')).endswith(suffix): out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
