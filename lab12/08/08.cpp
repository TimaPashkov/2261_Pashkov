
class Rectangle:
    def __init__(self,a,b):
        self.topleft = a
        self.bottomright = b
    def __str__(self):
        return '|'+str(self.topleft)+'-'+str(self.bottomright)+'|'
                       
                 
r=Rectangle(Point(0,10), Point(10,0))
print(r)
           