# problem title : Search Students Eligible for Scholarship
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
min_cgpa=float(q.get('min_cgpa',0)); max_income=float(q.get('max_income',10**100))
for r in records:
    try:
        if float(r.get('cgpa',0))>=min_cgpa and float(r.get('family_income',10**100))<=max_income: out.append(r)
    except (TypeError,ValueError): pass
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
