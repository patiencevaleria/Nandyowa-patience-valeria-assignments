import std;
using namespace std;

class Rectangle {
private:
    double width = 0;
    double length = 0;

public:
    // Set the dimensions
    void setWidth(double w) {
        width = w;
    }

    void setLength(double l) {
        length = l;
    }

    // Retrieve the dimensions
    double getWidth() const {
        return width;
    }

    double getLength() const {
        return length;
    }

    // Calculate area and perimeter
    double getArea() const {
        return width * length;
    }

    double getPerimeter() const {
        return 2 * (width + length);
    }
};

int main() {
    // Create the first rectangle
    Rectangle rectangle1;
    rectangle1.setWidth(5);
    rectangle1.setLength(10);

    cout << "Rectangle 1" << endl;
    cout << "Width: " << rectangle1.getWidth() << endl;
    cout << "Length: " << rectangle1.getLength() << endl;
    cout << "Area: " << rectangle1.getArea() << endl;
    cout << "Perimeter: " << rectangle1.getPerimeter() << endl;

    // Create the second rectangle
    Rectangle rectangle2;
    rectangle2.setWidth(4);
    rectangle2.setLength(6);

    cout << "\nRectangle 2" << endl;
    cout << "Width: " << rectangle2.getWidth() << endl;
    cout << "Length: " << rectangle2.getLength() << endl;
    cout << "Area: " << rectangle2.getArea() << endl;
    cout << "Perimeter: " << rectangle2.getPerimeter() << endl;

    return 0;
}