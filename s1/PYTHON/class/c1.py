class Publisher:
      
      def __init__(self,name ):
            self.name = name

      def display(self):
            print(f"Publisher Name : { self.name }")     

class Book(Publisher):

     def __init__(self, name, title, Author):
           super().__init__(name)
           self.title = title
           self.Author = Author

     def display(self):
           super().display()
           print(f"Book Title : { self.title }")
           print(f"Name of The Author : { self.Author }")

    
class Python(Book):

      def __init__(self, name, title, Author, price, no_of_pages):
            super().__init__(name, title, Author )
            self.price = price
            self.no_of_pages = no_of_pages

      def display(self):
            super().display()
            print(f"Price of the book : { self.price }")
            print(f"No Of Pages : { self.price }")

py_Book = Python("Coding", "Learn Python", "Umesh", "150", "100")
py_Book.display()                        