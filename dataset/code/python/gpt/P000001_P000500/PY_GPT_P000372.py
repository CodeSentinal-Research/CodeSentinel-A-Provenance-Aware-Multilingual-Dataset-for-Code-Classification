# problem title : Search Student by Roll Number
# The source statement does not define record serialization, so this implementation uses JSON records.
import json,sys
data=json.load(sys.stdin)
records=data.get("records",data if isinstance(data,list) else [])
query=data.get("query")
key='roll_number'
for r in records:
    if str(r.get(key,""))==str(query):
        print(json.dumps(r,ensure_ascii=False,separators=(",",":"))); break
else: print('Record Not Found')
