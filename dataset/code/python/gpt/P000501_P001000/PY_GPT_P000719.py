# problem title : Restore IP Addresses
# Solve the stated task using standard input and standard output.
import sys
def restore_ip(s, idx, parts):
    if len(parts) == 4:
        if idx == len(s): print(".".join(parts))
        return
    for l in range(1, 4):
        if idx + l <= len(s):
            part = s[idx:idx+l]
            if (part[0] == '0' and len(part) > 1) or int(part) > 255: continue
            restore_ip(s, idx + l, parts + [part])
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        restore_ip(tokens[0], 0, [])
if __name__ == '__main__':
    main()
