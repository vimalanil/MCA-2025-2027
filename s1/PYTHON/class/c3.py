class Person:

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def display(self):
        print(f"Name of the Person : { self.name }")
        print(f"Age of the person : { self.age }")

class Employee(Person):

    def __init__(self, name, age, empID):
        super().__init__(name, age)
        self.empID = empID

    def display(self):
        super().display()
        print(f"Employee ID : { self.empID}")

class Faculty(Employee):

    def __init__(self, name, age, empID , department ):
        super().__init__(name, age, empID)
        self.department = department

    def display(self):
        super().display()
        print(f"Department : { self.department }")

class Researcher:

    def can_do_research(self):
        return " This person can conduct Research. "

class Professor(Faculty , Researcher):

    pass

p = Professor("Alice", "45", "E102", "Computer Science")
p.display()
print(p.can_do_research())

