import random

class Arr_T:
    size: int
    arr: [int]

    def __init__(self):
        self.size = 0
        self.arr = []

    def make_Arr(self, size: int):
        self.size = size
        self.arr = [None] * self.size
        return self.arr

    def populate_Arr(self):
        for i in range(self.size):
            self.arr[i] = random.randint(1, 99)

    def within_Arr(self, val: int) -> bool:
        for i in range(self.size):
            if val == self.arr[i]:
                return True
        return False

    def largestIndIn_Arr(self) -> int:
        li = 0
        i = 0
        for i in range(self.size):
            if self.arr[i] > self.arr[li]:
                li = i
        return li

    def print_Arr(self):
        print("[" + ', '.join(str(x) for x in self.arr) + "]", sep = ', ')

    def swap(self, ind1: int, ind2: int):
        if self.arr[ind1] != self.arr[ind2]:
            self.arr[ind1], self.arr[ind2] = self.arr[ind2], self.arr[ind1]

    def sorted_populate_Arr(self):
        for i in range (self.size):
            self.arr[i] = i + 1

    def shuffle_Arr(self):
        if (self.arr > 1):
            for i in range(self.size):
                j = i + random.randint((random.randint(max, max) / self.size - i)) + 1
                self.swap(i, j)

    #Does not work correctly yet
    def combine_Arrs(self, B):
        N = self.Arr_T()
        N = self.make_Arr(self.size + B.size)
        for i in range(self.size):
            N.arr[i] = self.arr[i]
        for j in range(self.size, N.size):
            N.arr[j] = B.arr[j - self.size]


    def set_Value(self, value: int, ind: int):
        self.arr[ind] = value



'''
if __name__ == "__main__":
    array = Arr_T()
    array.make_Arr(50)
    array2 = Arr_T()
    array2.make_Arr(50)
    array.populate_Arr()
    array2.populate_Arr()
    print("Array before combining: ")
    array.print_Arr()
    array.combine_Arrs(array2)
    print("Array after combining: ")
    array.print_Arr()
    '''
