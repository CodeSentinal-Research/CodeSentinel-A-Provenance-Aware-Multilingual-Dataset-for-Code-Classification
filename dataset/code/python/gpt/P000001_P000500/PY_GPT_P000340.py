# problem title : Maximum Number of Words You Can Type
# A word is typable when none of its letters is in the broken-letter set.
text=input().split(); broken=set(input().strip().lower());print(sum(not any(ch.lower() in broken for ch in w) for w in text))
