# problem title : Search Products Eligible for Free Shipping
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
limit=float(q.get('minimum_price',q.get('threshold',0)))
for r in records:
    try:
        if float(r.get('price',0))>=limit: out.append(r)
    except (TypeError,ValueError): pass
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
