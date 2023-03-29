#!/usr/bin/env python3

from decimal import Decimal

DENOMINATIONS = {"Hundred": 100, "Fifty": 50, "Twenty": 20, "Ten": 10, "Five": 5, "One": 1, "Quarter": 0.25, "Dime": 0.1, "Nickel": 0.05, "Penny": 0.01}

def count_change(currency: float) -> dict:
    change = {}

    for denomination, value in DENOMINATIONS.items():
        removed = int(currency / value)
        currency = float(Decimal(str(currency)) - Decimal(str(removed * value)))

        change[denomination] = removed

    return change

print(count_change(5.26))
print(count_change(103.57))
print(count_change(53.97))

