Here is the Python code for the given problem:

def sentences_similarity():
    sentence1 = input().split()
    sentence2 = input().split()
    P = int(input())

    similar_pairs = {}

    for i in range(P):
        pair = tuple(input().split())
        similar_pairs[pair[0]] = pair[1]

    def is_similar(sentence1, sentence2):
        if not sentence1 and not sentence2:
            return True
        if not sentence1 or not sentence2:
            return False
        if len(sentence1) != len(sentence2):
            return False
        if sentence1 != sentence2:
            return False
        for word1 in sentence1.split():
            if word1 not in similar_pairs:
                return False
        for word2 in sentence2.split():
            if word2 != similar_pairs[word1]:
                return False
        return True

    if is_similar(sentence1, sentence2):
        print('YES')
    else:
        print('NO')

sentences_similarity()
In this code, we first read the first sentence and the second sentence. Then we read the number of similar pairs. We create an empty dictionary to store the similar pairs. We read the similar pairs and add them to the dictionary. Finally, we define a function to check if the two sentences are similar. If they are, we print 'YES'; otherwise, we print 'NO'.