class Currency:
    def __init__(self, amount, unit):
        self.amount = amount
        self.unit = unit

    def __eq__(self, other):
        if not isinstance(other, Currency):
            return False
        return self.amount == other.amount and self.unit == other.unit


c1 = Currency(100, "USD")
c2 = Currency(100, "USD")
c3 = Currency(200, "USD")
c4 = Currency(100, "EUR")

print(c1 == c2)   
print(c1 == c3)   
print(c1 == c4)   
