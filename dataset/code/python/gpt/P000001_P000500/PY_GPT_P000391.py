# problem title : Search Students Above Minimum GPA
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
threshold=float(q.get('threshold',q.get('minimum',0)))
for r in records:
    try:
        if float(r.get('gpa',-1))>=threshold: out.append(r)
    except (TypeError,ValueError): pass
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
