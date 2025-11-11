class Engine:
    
    def __init__(self, power):
        self.power = power

    def display(self):
        print(f"Power of the Engine : { self.power }")

class wheels:
    def __init__(self, size):
        self.size = size

    def display(self):
        print(f"Size of the Wheel : { self.size }")

class car( Engine , wheels ):

    def __init__(self, power, size, model):
        Engine.__init__(self, power)
        wheels.__init__(self, size)
        self.model = model

    def display(self):
        print(f"Car Model : {self.model}")
        Engine.display(self)
        wheels.display(self)     

car_details = car( "480", "20", "GT")
car_details.display()        