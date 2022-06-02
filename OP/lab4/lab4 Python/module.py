from LinearFunction import LinearFunction
from QuadraticFunction import QuadraticFunction
from random import randint


def create_linear_list():
    size = int(input("Enter number of linear functions n:"))
    list = []
    for i in range(size):
        y = LinearFunction(randint(-100, 100), randint(-100, 100))
        list.append(y)
    return list


def create_quadratic_list():
    size = int(input("Enter number of quadratic functions m:"))
    list = []
    for i in range(size):
        y = QuadraticFunction(randint(-100, 100), randint(-100, 100), randint(-100, 100))
        list.append(y)
    return list


def print_list(list):
    for func in list:
        func.print()


def change_funcs(list, mode, num):
    for func in list:
        if mode == '+':
            func.increase_by(num)
        elif mode == '-':
            func.decrease_by(num)


def max_function(list, x):
    max_f = list[0]
    max_val = list[0].calculate(x)
    for i in range(1, len(list)):
        if list[i].calculate(x) > max_val:
            max_f = list[i]
            max_val = list[i].calculate(x)
    return max_f, max_val


def find_max_function(linear_list, quadratic_list, x):
    max_linear, max_lin_value = max_function(linear_list, x)
    max_quadratic, max_quad_value = max_function(quadratic_list, x)
    if max_lin_value > max_quad_value:
        return max_linear, max_lin_value
    else:
        return max_quadratic, max_quad_value