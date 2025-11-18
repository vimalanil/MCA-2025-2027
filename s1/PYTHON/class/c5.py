class FruitBasket:
    def __init__(self, fruits=None):
        # fruits will be stored as a dictionary: {fruit_name: price_per_kg}
        self.fruits = fruits if fruits is not None else {}

    def __add__(self, other):
        # Create a new dictionary for the result
        result = {}

        # Add fruits from the first basket
        for fruit, price in self.fruits.items():
            result[fruit] = price

        # Add fruits from the second basket
        for fruit, price in other.fruits.items():
            # If fruit exists in both, choose the least price
            if fruit in result:
                result[fruit] = min(result[fruit], price)
            else:
                result[fruit] = price

        # Return new FruitBasket containing merged fruits
        return FruitBasket(result)

    def display(self):
        for fruit, price in self.fruits.items():
            print(f"{fruit} : {price} per kg")
