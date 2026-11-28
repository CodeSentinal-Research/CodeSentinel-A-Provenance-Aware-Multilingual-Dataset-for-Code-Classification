def restoreIpAddresses(s):
    def backtrack(start, temp, count):
        if count > 4 or count == 4 and start == len(s):
            if count == 4:
                ans.append(temp[0] + '.' + temp[1] + '.' + temp[2] + '.' + temp[3])
            return
        for i in range(start, min(start + 3, len(s))):
            curr = s[start:i + 1]
            if (curr[0] == '0' and len(curr) != 1) or curr[0] == '0':
                continue
            if 0 <= int(curr) <= 255:
                temp.append(curr)
                backtrack(i + 1, temp, count + 1)
                temp.pop()

    ans = []
    backtrack(0, [], 0)
    return ans

def main():
    s = input()
    print(restoreIpAddresses(s))

if __name__ == "__main__":
    main()