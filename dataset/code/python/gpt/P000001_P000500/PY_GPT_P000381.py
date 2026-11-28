# problem title : Search Contact by Name
# The source statement does not define record serialization, so this implementation uses JSON records.
import json,sys
data=json.load(sys.stdin)
records=data.get("records",data if isinstance(data,list) else [])
query=data.get("query")
key='name'
for r in records:
    if str(r.get(key,""))==str(query):
        print(json.dumps(r,ensure_ascii=False,separators=(",",":"))); break
else: print('Contact Not Found')
