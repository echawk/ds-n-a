import random


def get_max(lst):
    max_ind = 0
    for i in range(len(lst)):
        if lst[i] > lst[max_ind]:
            max_ind = i
    return lst[max_ind]

def get_place(num, place):
    return (num / place) % 10

def counting_sort(lst, place):
    output = []
    for i in range(len(lst) + 1):
        output.append(0)
    mx = get_place(lst[0], place)
    i = 1
    while i < len(lst):
        if get_place(lst, place) > mx:
            mx = lst[i]
        i +=1 

# FIXME
def radix_sort(lst):



if __name__ == "__main__":
    l = []
    n = 100
    for i in range(n):
        l.append(random.randint(0, n))
    print(l)
    radix_sort(l)
    print(l)
