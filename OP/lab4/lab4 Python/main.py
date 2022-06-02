from module import *

list1 = create_linear_list()
list2 = create_quadratic_list()

print("Linear functions: ")
print_list(list1)

print("Quadratic functions: ")
print_list(list2)

change_funcs(list1, '+', 3)
print("\nIncreased by 3 linear functions: ")
print_list(list1)

change_funcs(list2, '-', 2)
print("Decreased by 2 quadratic functions: ")
print_list(list2)

x0 = int(input("Enter value of a dot: "))
max_func, max_value = find_max_function(list1, list2, x0)
print(f"Function with a max value in a dot {x0}")
max_func.print()
print(f"Value = {max_value}")
