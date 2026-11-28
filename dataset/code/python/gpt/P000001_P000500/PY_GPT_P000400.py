# problem title : Search Employees by Salary Range
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
lo=q.get('min',q.get('minimum',0)); hi=q.get('max',q.get('maximum',10**100))
for r in records:
    try:
        if lo<=float(r.get('salary',0))<=hi: out.append(r)
    except (TypeError,ValueError): pass
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
