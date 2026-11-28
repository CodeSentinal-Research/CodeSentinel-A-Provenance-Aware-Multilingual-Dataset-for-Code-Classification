s = input().strip()
import re
if re.match(r'^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?$', s):
    print("Valid")
else:
    print("Invalid")
