from itertools import combinations

def restore_ip(s):
    ip = []
    for i in range(1, 4):
        if s:
            if s[0] == '0' and len(s) > 1 or s[:i] > '255':
                return []
            ip.append(s[:i])
            s = s[i:]
        else:
            if len(ip) < 3:
                return []
            ip.append(s)
            return ['.'.join(ip[i] for i in range(3)) for i in range(3)]
    return []

def main():
    s = input()
    ip = restore_ip(s)
    if ip:
        for ip in sorted(ip):
            print(ip)
    else:
        print('No valid IPs')

if __name__ == '__main__':
    main()