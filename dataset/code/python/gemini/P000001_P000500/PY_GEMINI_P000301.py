import sys

def restore_ip_addresses(s: str):
    res = []
    def backtrack(idx, parts):
        if len(parts) == 4:
            if idx == len(s):
                res.append('.'.join(parts))
            return
        for length in range(1, 4):
            if idx + length <= len(s):
                segment = s[idx:idx+length]
                if (segment.startswith('0') and len(segment) > 1) or int(segment) > 255:
                    continue
                parts.append(segment)
                backtrack(idx + length, parts)
                parts.pop()
    backtrack(0, [])
    return res

def main():
    input_data = sys.stdin.read().split()
    if input_data:
        s = input_data[0]
        for ip in restore_ip_addresses(s):
            print(ip)

if __name__ == '__main__':
    main()