# moshmosh?
# +pattern-matching


class GreaterThan:
    def __init__(self, v):
        self.v = v

    def __match__(self, cnt: int, to_match):
        if isinstance(to_match, int) and cnt == 0 and to_match > self.v:
            return ()  # matched
        # 'return None' indicates 'unmatched'


with match(114, 514):
    if (GreaterThan(42)() and a, b):
        print(b, a)
# 514 114
