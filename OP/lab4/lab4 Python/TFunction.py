class TFunction:
    def __init__(self, a, b, c=0):
        self._a = a
        self._b = b
        self._c = c

    def increase_by(self, num):
        self._a += num
        self._b += num
        self._c += num

    def decrease_by(self, num):
        self._a -= num
        self._b -= num
        self._c -= num

    def print(self):
        pass

    def calculate(self, x):
        pass



