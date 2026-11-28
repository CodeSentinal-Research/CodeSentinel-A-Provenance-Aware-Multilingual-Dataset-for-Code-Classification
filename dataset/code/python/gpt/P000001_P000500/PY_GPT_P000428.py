# problem title : Search Events Happening Today
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
day=str(q.get('date',q.get('today','')))
for r in records:
    if str(r.get('date',''))==day: out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
