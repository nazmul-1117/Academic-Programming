tuplex = ("w", 3, "r", "e", "s", "o", "u", "r", "c", "e")

# value: "w", 3, "r", "e", "s", "o", "u", "r", "c", "e"
# pos_i:  0,  1,  2,   3,   4,   5,   6,   7,   8,   9
# neg_i: -10, -9, -8, -7,  -6,  -5,  -4,  -3,  -2,  -1

# positive_index 4th: e
# negative_index 4th: u

print(f'Tuple: {tuplex}')
print(f'4th element from the beginning: {tuplex[3]}')
print(f'4th element from the last: {tuplex[-4]}')