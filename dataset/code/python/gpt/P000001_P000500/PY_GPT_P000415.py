# problem title : Search Patients by Blood Group
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
for r in records:
    if str(r.get('blood_group',''))==str(q.get('blood_group',q.get('value',q.get('query','')))): out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
