class Solution:
    def romanToInt(self, s: str) -> int:

        # Create a map between roman symbols and values:
        rom_to_int = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }

        # Make an array and convert each symbol of the provided Roman number into an integer:
        values_array = [rom_to_int.get(char) for char in s]

        print(values_array)
        # Create an array to store converted Roman number for substructions:
        integer = 0

        for i in enumerate(values_array):
            substruction_check1 = values_array[i] * 5 - values_array[i + 1]
            substruction_check2 = values_array[i] * 10 - values_array[i + 1]

            if substruction_check1 == 0 or substruction_check2 == 0:
                integer += values_array[i + 1] - values_array[i]
                i += 1
            else:
                integer += values_array[i]

        return(integer)
