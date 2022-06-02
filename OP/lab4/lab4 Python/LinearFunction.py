from TFunction import TFunction


class LinearFunction(TFunction):

    def calculate(self, x):
        return self._a * x + self._b

    def print(self):
        if self._a == 0:
            print(f"y = {self._b}", end="")
        elif self._a == 1:
            print("y = x", end="")
        elif self._a == -1:
            print("y = -x", end="")
        else:
            print(f"y = {self._a}x", end="")

        if self._b > 0:
            print(f" + {self._b}")
        elif self._b < 0:
            print(f" - {abs(self._b)}")


