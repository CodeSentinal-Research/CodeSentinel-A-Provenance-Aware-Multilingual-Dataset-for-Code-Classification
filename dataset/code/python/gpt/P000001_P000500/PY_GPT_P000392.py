# problem title : Search Files by Extension
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
ext=str(q.get('extension',q.get('value','')))
for r in records:
    name=str(r.get('name',r if isinstance(r,str) else ''))
    if name.endswith(ext if ext.startswith('.') else '.'+ext): out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
