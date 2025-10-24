my_list = [1, 2, 3, 4, 5, 6, 7, 8, 9]
even_count = 0
odd_count = 0

for num in my_list:
    if num % 2 == 0:
        even_count += 1
    else:
        odd_count += 1

print(f'Total Even numbers in the list: {even_count}')
print(f'Total Odd numbers in the list: {odd_count}')