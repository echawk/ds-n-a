import random


def gnome_sort(lst):
    pos = 0

    while pos < len(lst):
        if (pos == 0) or (lst[pos] >= lst[pos - 1]):
            pos += 1
        else:
            t = lst[pos]
            lst[pos] = lst[pos - 1]
            lst[pos - 1] = t
            pos -= 1


if __name__ == "__main__":
    l = []
    n = 100
    for i in range(n):
        l.append(random.randint(0, n))
    print(l)
    gnome_sort(l)
    print(l)
