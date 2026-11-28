# problem title : Search Books Published After Given Year
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
year=int(q.get('year',q.get('after_year',0)))
for r in records:
    try:
        if int(r.get('publication_year',0))>year: out.append(r)
    except (TypeError,ValueError): pass
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
