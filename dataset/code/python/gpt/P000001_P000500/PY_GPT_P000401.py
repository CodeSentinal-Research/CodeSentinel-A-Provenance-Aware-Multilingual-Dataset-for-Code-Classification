# problem title : Search Products with Low Stock
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
limit=float(q.get('threshold',q.get('stock_threshold',0)))
for r in records:
    try:
        if float(r.get('stock',0))<limit: out.append(r)
    except (TypeError,ValueError): pass
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
