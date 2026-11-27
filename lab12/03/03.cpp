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
    box *x = new box (10, 6, 3);
    box *y = new box (8, 8, 8);
    if (y->volume() > x->volume()){
        std::cout << "Volume y greater than volume x" << std::endl;
    }else{
        std::cout << "Volume x greater than volume y" << std::endl;
    }

    if (y->surface() > x->surface()) {
        std::cout << "Surface y greater than surface x" << std::endl;
    } else {
        std::cout << "Surface x greater than surface y" << std::endl;
    }
    delete x;
    delete y;
    return 0;
}
