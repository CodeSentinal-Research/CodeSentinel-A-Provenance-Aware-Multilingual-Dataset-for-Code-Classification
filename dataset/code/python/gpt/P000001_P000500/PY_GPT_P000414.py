# problem title : Search Available Flights Within Budget
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
budget=float(q.get('budget',q.get('maximum',0)))
for r in records:
    try:
        if bool(r.get('available',False)) and float(r.get('price',0))<=budget: out.append(r)
    except (TypeError,ValueError): pass
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
