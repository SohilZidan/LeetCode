class Solution:
    ops = {
        "+": lambda x,y: x+y,
        "-": lambda x,y: x-y,
        "*": lambda x,y: x*y,
        "/": lambda x,y: x/y,
    }
    def evalRPN(self, tokens: List[str]) -> int:
        evaluated = []
        for token in tokens:
            if token not in ["+", "-", "/", "*"]:
                evaluated.append(int(token))
            else:
                right = evaluated.pop()
                left = evaluated.pop()
                res = self.ops[token](left, right)
                evaluated.append(int(res))
                
            # print(evaluated)
        return int(evaluated.pop())
                