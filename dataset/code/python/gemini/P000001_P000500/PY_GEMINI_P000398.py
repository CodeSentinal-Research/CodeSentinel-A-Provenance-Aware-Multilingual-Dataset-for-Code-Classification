import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vehicles = []
        idx = 1
        for _ in range(n):
            vname = tokens[idx]
            manuf = tokens[idx+1]
            vehicles.append((vname, manuf))
            idx += 2
        target_manuf = tokens[idx]
        for vname, manuf in vehicles:
            if manuf == target_manuf:
                print(vname)

if __name__ == '__main__':
    main()