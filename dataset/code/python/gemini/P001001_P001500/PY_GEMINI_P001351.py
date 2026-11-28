class CombinationIterator:
    def __init__(self, characters: str, combinationLength: int):
        self.combinations = []
        n = len(characters)

        def backtrack(start: int, cur: str):
            if len(cur) == combinationLength:
                self.combinations.append(cur)
                return
            for i in range(start, n):
                backtrack(i + 1, cur + characters[i])

        backtrack(0, "")
        self.idx = 0

    def next(self) -> str:
        res = self.combinations[self.idx]
        self.idx += 1
        return res

    def hasNext(self) -> bool:
        return self.idx < len(self.combinations)