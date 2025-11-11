class Person:

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def display(self):
        print(f"Name of the Person : { self.name }")
        print(f"Age of the person : { self.age }")

class Employee(Person):

    def __init__(self, name, age, empID):
        super().__init__(self, name, age)
        self.empID = empID

    def display(self):
        super().display(self)
        print(f"Employee ID : { self.empID}")

class         


