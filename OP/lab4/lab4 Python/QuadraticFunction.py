from TFunction import TFunction


class QuadraticFunction(TFunction):

    def calculate(self, x):
        return self._a * x ** 2 + self._b * x + self._c

    def print(self):
        if self._a == 0:
            print("y = ", end="")
        elif self._a == 1:
            print("y = x^2", end="")
        elif self._a == -1:
            print("y = -x", end="")
        else:
            print(f"y = {self._a}x^2", end="")

        if self._b == 1:
            print(" + x", end="")
        elif self._b == -1:
            print(" - x", end="")
        elif self._b != 0:
            if self._a != 0:
                if self._b > 0:
                    print(f" + {self._b}x", end="")
                else:
                    print(f" - {abs(self._b)}x", end="")
            else:
                print(f" {self._b}x", end="")

        if self._a == 0 and self._b == 0:
            print(self._c)
        elif self._c > 0:
            print(f" + {self._c}")
        elif self._c < 0:
            print(f" - {abs(self._c)}")
