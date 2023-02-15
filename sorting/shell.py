import random


# FIXME: doesn't end
def shell_sort(lst):
    gap = int(len(lst) / 2)
    while gap > 0:
        x = gap
        while x < len(lst):
            y = int(x - gap)
            while y >= 0:
                if lst[int(y + gap)] > lst[int(y)]:
                    break
                else:
                    t = lst[int(y)]
                    lst[int(y)] = lst[int(y + gap)]
                    lst[int(y + gap)] = t
                y -= gap
            x += 1
        gap /= 2


if __name__ == "__main__":
    l = []
    n = 100
    for i in range(n):
        l.append(random.randint(0, n))
    print(l)
    shell_sort(l)
    print(l)
