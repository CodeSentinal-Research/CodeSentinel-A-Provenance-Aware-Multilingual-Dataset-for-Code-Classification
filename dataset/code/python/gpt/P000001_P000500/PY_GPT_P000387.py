# problem title : Search Transaction by Transaction ID
# The source statement does not define record serialization, so this implementation uses JSON records.
import json,sys
data=json.load(sys.stdin)
records=data.get("records",data if isinstance(data,list) else [])
query=data.get("query")
key='transaction_id'
for r in records:
    if str(r.get(key,""))==str(query):
        print(json.dumps(r,ensure_ascii=False,separators=(",",":"))); break
else: print('Transaction Not Found')
