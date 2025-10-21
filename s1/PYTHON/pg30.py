area_square = lambda side: side * side
area_rectangle = lambda l, b: l * b
area_triangle = lambda b, h: 0.5 * b * h

print("Square:", area_square(4))
print("Rectangle:", area_rectangle(5, 6))
print("Triangle:", area_triangle(10, 5))
