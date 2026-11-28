import re
with open('input/4.txt') as f:
    content = f.read().split("\n\n")
    content = [c.replace('\n', ' ') for c in content]
print(len(content))
# for line in content:
#   if re.search(r'pid:720439412', line):
#     print(line)

class Passport(object):
  def __init__(self):
    self._byr = None
    self._iyr = None
    self._eyr = None
    self._hgt = None
    self._hcl = None
    self._ecl = None
    self._pid = None
    self._cid = None

  @property
  def byr(self):
    return self._byr
  
  @property
  def iyr(self):
    return self._iyr
  
  @property
  def eyr(self):
    return self._eyr
  
  @property
  def hgt(self):
    return self._hgt
  
  @property
  def hcl(self):
    return self._hcl
  
  @property
  def ecl(self):
    return self._ecl
  
  @property
  def pid(self):
    return self._pid
  
  @property
  def cid(self):
    return self._cid
  
  @byr.setter
  def byr(self, v):
    if not v or v == '': raise Exception("byr cannot be empty")
    if int(v) < 1920 or int(v) > 2002:
      raise Exception("byr out of range")
    self._byr = v

  @iyr.setter
  def iyr(self, v):
    if not v or v == '': raise Exception("iyr cannot be empty")
    if int(v) < 2010 or int(v) > 2020:
      raise Exception("iyr out of range")
    self._iyr = v

  @eyr.setter
  def eyr(self, v):
    if not v or v == '': raise Exception("eyr cannot be empty")
    if int(v) < 2020 or int(v) > 2030:
      raise Exception("eyr out of range")
    self._eyr = v

  @hgt.setter
  def hgt(self, v):
    if not v or v == '': raise Exception("hgt cannot be empty")

    hr = re.search(r'^([0-9]{3})\s*(cm|in)$', v)
    h = hr.group(1)
    unit = hr.group(2)
    if unit == 'cm':
      if int(h) < 150 or int(h) > 193:
        raise Exception("hgt out of range")
    elif unit == 'in':
      if int(h) < 59 or int(h) > 76:
        raise Exception("hgt out of range")
    else:
      raise Exception("hgt invalid")
    self._hgt = v

  @hcl.setter
  def hcl(self, v):
    if not v or v == '': raise Exception("hcl cannot be empty")

    hr = re.match(r'^#[0-9a-f]{6}$', v)
    if not hr:
      raise Exception("hcl invalid")
    self._hcl = v

  @ecl.setter
  def ecl(self, v):
    if not v or v == '': raise Exception("ecl cannot be empty")

    valid = ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']
    if v not in valid:
      raise Exception("ecl invalid")
    self._ecl = v

  @pid.setter
  def pid(self, v):
    if not v or v == '': raise Exception("pid cannot be empty")
    if len(v) < 9: raise Exception("pid too short")
    if len(v) > 9: raise Exception("pid too long")
    if re.search('720439412', v):
      print(v)
    if not re.search(r'[0-9]{9}', v): raise Exception("pid incorrect")
    self._pid = v

  @cid.setter
  def cid(self, v):
    self._cid = v

  def __str__(self):
    return 'byr: ' + str(self.byr) + ' iyr: ' + str(self.iyr) + \
          ' eyr: ' + str(self.eyr) + ' hgt: ' + str(self.hgt) + \
          ' hcl: ' + str(self.hcl) + ' ecl: ' + str(self.ecl) + \
          ' pid: ' + str(self.pid) + ' cid: ' + str(self.cid)

  def is_valid(self):
    if not self.byr or not self.iyr or not self.eyr or not self.hgt or not self.hcl or not self.ecl or not self.pid:
      return False
    return True

def check_entries(entries):
  byr = iyr = eyr = hgt = hcl = ecl = pid = False
  for entry in entries:
    field = entry.split(':')[0].strip()
    value = entry.split(':')[1].strip()
    if not field or not value or value == '':
      return False
    if field == 'byr':
      byr = True
      if len(value) != 4:
        return False
      if int(value) < 1920 or int(value) > 2002:
        return False
    if field == 'iyr':
      iyr = True
      if len(value) != 4:
        return False
      if int(value) < 2010 or int(value) > 2020:
        return False
    if field == 'eyr':
      eyr = True
      if len(value) != 4:
        return False
      if int(value) < 2020 or int(value) > 2030:
        return False
    if field == 'hcl':
      hcl = True
      v = value.replace('#', '')
      if len(v) < 6 or len(v) > 6:
        return False
      if not re.search(r'[0-9a-fA-F]{6}', v):
        return False
    if field == 'ecl':
      ecl = True
      if not re.search(r'^(amb|blu|brn|gry|grn|hzl|oth)$', value):
        return False
      print(value)
    if field == 'hgt':
      hgt = True
      hr = re.search(r'([0-9]{2,3})(cm|in)', value)
      if not hr:
        return False
      h = hr.group(1)
      unit = hr.group(2)
      if unit == 'cm':
        if int(h) < 150 or int(h) > 193:
          return False
      elif unit == 'in':
        if int(h) < 59 or int(h) > 76:
          return False
      else:
        return False
    if field == 'pid':
      pid = True
      p = value
      if len(p) > 9 or len(p) < 9:
        return False
      if not re.search(r'[0-9]{9}', p):
        return False
  if byr and iyr and eyr and hgt and hcl and ecl and pid:
    return True
  print([x for x in [byr, iyr, eyr, hgt, hcl, ecl, pid]])
  print(entries)
  return False

invalid = 0
valid = 0
valids = []
# for line in content:
#   entries = line.split()
  # if check_entries(entries):
  #   valid += 1
  #   valids.append(entries)
  # else:
  #   invalid += 1
  # for e in entries:
  #   field = e.split(':')[0]
  #   if not re.search(r'(byr|iyr|eyr|hgt|hcl|ecl|pid|cid)', e):
  #     invalid += 1
  #     break
  #   value = e.split(':')[1]
  #   if not value:
  #     invalid += 1
  #     break
  #   valid_entries = True
  # if valid_entries:
  #   valid += 1

# print(invalid)
# print(valid)


pp = Passport()
pps = []
valid = 0
for line in content:
  # need all fields
  if 'byr' not in line:
    continue
  if 'iyr' not in line:
    continue
  if 'eyr' not in line:
    continue
  if 'hgt' not in line:
    continue
  if 'ecl' not in line:
    continue
  if 'hcl' not in line:
    continue
  if 'pid' not in line:
    continue

  byr = re.search(r'byr:(\d{4})', line)
  if not byr:
    continue
  byr = byr.group(1)
  if int(byr) < 1920 or int(byr) > 2002:
    continue
  iyr = re.search(r'iyr:(\d{4})', line)
  if not iyr:
    continue
  iyr = iyr.group(1)
  if int(iyr) < 2010 or int(iyr) > 2020:
    continue
  eyr = re.search(r'eyr:(\d{4})', line)
  if not eyr:
    continue
  eyr = eyr.group(1)
  if int(eyr) < 2020 or int(eyr) > 2030:
    continue
  hgt = re.search(r'hgt:(\d+)cm', line)
  if hgt:
    hgt = hgt.group(1)
    if int(hgt) < 150 or int(hgt) > 193:
      continue
  else:
    hgt = re.search(r'hgt:(\d+)in', line)
    if hgt:
      hgt = hgt.group(1)
      if int(hgt) < 59 or int(hgt) > 76:
        continue
    else:
      continue
  hcl = re.search(r'hcl:#([0-9a-f]+)', line)
  if not hcl:
    continue
  hcl = hcl.group(1)
  if len(hcl) > 6:
    continue
  ecl = re.search(r'ecl:(amb|blu|brn|gry|grn|hzl|oth)', line)
  if not ecl:
    continue
  pid = re.search(r'pid:(\d+)', line)
  if not pid:
    continue
  pid = pid.group(1)
  if len(pid) != 9:
    continue
  valid += 1

  entries = line.split()
  pp = Passport()
  for entry in entries:
    field = entry.split(':')[0].strip()
    value = entry.split(':')[1].strip()
    try:
      setattr(pp, field, value)
    except:
      break
  if pp.is_valid():
    pps.append(pp)
print(len(pps))
print(valid)

# byr = list(set([p.byr for p in pps]))
# print(byr)
# iyr = list(set([p.iyr for p in pps]))
# print(iyr)
# eyr = list(set([p.eyr for p in pps]))
# print(eyr)
# ecl = list(set([p.ecl for p in pps]))
# print(ecl)
# hcl = list(set([p.hcl for p in pps]))
# print(hcl)
# hgt = list(set([p.hgt for p in pps]))
# print(hgt)
# pid = list(set([p.pid for p in pps]))
# print(pid)
