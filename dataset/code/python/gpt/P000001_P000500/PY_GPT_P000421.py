# problem title : Search Expired Memberships
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
today=str(q.get('date',q.get('current_date','')))
for r in records:
    if str(r.get('expiry_date',''))<today: out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
