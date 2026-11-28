# problem title : Search Orders Pending for More Than N Days
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
days=int(q.get('days',q.get('n',0))); today=datetime.date.fromisoformat(str(q.get('current_date')))
for r in records:
    if str(r.get('status','')).casefold()=='pending':
        try:
            placed=datetime.date.fromisoformat(str(r.get('order_date')))
            if (today-placed).days>days: out.append(r)
        except ValueError: pass
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
