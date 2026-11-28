def remove_consonants(S):
    consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"
    no_consonants = "".join([c for c in S if c not in consonants])
    return no_consonants

S = input("Enter a string: ")
print("After removing consonants:", remove_consonants(S))