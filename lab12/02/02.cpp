#include <iostream>

class box{
private:
    double length;
    double width;
    double height;
public:
    box(double _length, double _width, double _height):
        length(_length), width(_width), height(_height){
    }
    double volume();
    double surface();
};

double box::volume(){
    return length * width * height;
};
double box::surface(){
    return 2 * (length * width + length * height + width * height);
};

int main(){
    box a(10, 6, 3);
    std::cout << "Object size = " << sizeof(a) << std::endl;
    std::cout << "Volume = " << a.volume() << std::endl;
    std::cout << "Surface = " << a.surface() << std::endl;
}
