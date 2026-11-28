def strStr(haystack: str, needle: str) -> int:
    if needle == "":
        return 0
    if haystack == "":
        return -1
    if len(haystack) < len(needle):
        return -1

    for i in range(len(haystack) - len(needle) + 1):
        if haystack[i:i+len(needle)] == needle:
            return i
    return -1

def main():
    print(strStr("hello", "ll"))  
    print(strStr("hello", "hi"))  
    print(strStr("", ""))         
    print(strStr("a", "a"))       
    print(strStr("aaaaa", "aaa")) 
    print(strStr("aaaaa", "b"))   

if __name__ == "__main__":
    main()