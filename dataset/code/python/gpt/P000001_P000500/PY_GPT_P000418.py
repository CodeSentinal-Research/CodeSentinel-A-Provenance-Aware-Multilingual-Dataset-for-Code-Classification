# problem title : Search Employees Joined Before a Given Date
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
d=str(q.get('date',''))
for r in records:
    if str(r.get('joining_date',''))<d: out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
