class Solution:
    key_map = {
    "2": ["a", "b", "c"],
    "3": ["d", "e", "f"],
    "4": ["g", "h", "i"],
    "5": ["j", "k", "l"],
    "6": ["m", "n", "o"],
    "7": ["p", "q", "r", "s"],
    "8": ["t", "u", "v"],
    "9": ["w", "x", "y", "z"]
    }
    def letterCombinations(self, digits: str) -> List[str]:
        found_words = []
        # 1. iterate over numbers
        for num in digits:
            corres_chars = self.key_map[num]
            if len(found_words) == 0:
                found_words = corres_chars
                continue

            tmp_found_words = found_words
            found_words = []
            for ch in corres_chars:
                partial_found_words = [res_ele+ch for res_ele in tmp_found_words]
                found_words += partial_found_words

        # found_words = [word for word in found_words if word in valid_words]
        return found_words
        