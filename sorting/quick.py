import random


def partition(lst, low, high):
    pivot = lst[high]
    i = low - 1
    j = low
    while j <= high:
        if lst[j] < pivot:
            i += 1
            # Swap i & j
            t = lst[j]
            lst[j] = lst[i]
            lst[i] = t
        j += 1
    t = lst[i + 1]
    lst[i + 1] = lst[high]
    lst[high] = t
    return i + 1


def quick_sort_driver(lst, low, high):
    if low < high:
        pi = partition(lst, low, high)
        quick_sort_driver(lst, low, pi - 1)
        quick_sort_driver(lst, pi + 1, high)


def quick_sort(lst):
    quick_sort_driver(lst, 0, len(lst) - 1)


if __name__ == "__main__":
    l = []
    n = 100
    for i in range(n):
        l.append(random.randint(0, n))
    print(l)
    quick_sort(l)
    print(l)
