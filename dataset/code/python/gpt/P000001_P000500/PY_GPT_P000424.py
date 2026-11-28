# problem title : Search Duplicate Email Addresses
# The source does not specify record serialization; use JSON with a records array and query fields.
import json,sys,datetime
data=json.load(sys.stdin)
records=data.get('records',[])
q=data.get('query',data)
out=[]
from collections import Counter
counts=Counter(str(r.get('email','')) for r in records); print(json.dumps(sorted([e for e,c in counts.items() if c>1]),ensure_ascii=False)); sys.exit()
print(json.dumps(out,ensure_ascii=False,separators=(',',':')))
