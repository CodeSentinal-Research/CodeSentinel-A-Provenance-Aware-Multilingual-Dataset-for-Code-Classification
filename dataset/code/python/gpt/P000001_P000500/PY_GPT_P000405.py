# problem title : Search Courses by Instructor
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
for r in records:
    if str(r.get('instructor',''))==str(q.get('instructor',q.get('value',q.get('query','')))): out.append(r)
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
