# problem title : Search Active Employees in a Department
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
dept=str(q.get('department',q.get('query','')))
for r in records:
    if str(r.get('department',''))==dept and bool(r.get('active',False)): out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
