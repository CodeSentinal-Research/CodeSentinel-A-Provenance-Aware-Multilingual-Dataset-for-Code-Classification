def canConstruct(ransomNote: str, magazine: str) -> str:
    if len(ransomNote) > len(magazine):
        return "No"

    dict_magazine = {}
    for char in magazine:
        if char not in dict_magazine:
            dict_magazine[char] = 1
        else:
            dict_magazine[char] += 1

    for char in ransomNote:
        if char not in dict_magazine or dict_magazine[char] == 0:
            return "No"
        else:
            dict_magazine[char] -= 1

    return "Yes"

def main():
    ransomNote = input()
    magazine = input()
    print(canConstruct(ransomNote, magazine))

if __name__ == "__main__":
    main()