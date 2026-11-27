#include <iostream>

class box{
private:
    double length;
    double width;
    double height;
    static int count;
public:
    box(double _length, double _width, double _height):
        length(_length), width(_width), height(_height){
    }
    double volume();
    double surface();
    void addr();
};

double box::volume(){
    return length * width * height;
};
double box::surface(){
    return 2 * (length * width + length * height + width * height);
};

void box::addr(){
    std:: cout << &length << " " << &width << " " << &height << " " << &count << std::endl;
}
int box::count = 0;

box c(12,10,1);

int main(){
    box a(10,8,3);
    box *b = new box(8,8,8);
    a.addr();
    b->addr();
    c.addr();
    return 0;
}
