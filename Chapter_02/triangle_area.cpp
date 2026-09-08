// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6


// Geometry: area of a triangle
// Write a program that prompts the user to enter the three points
// (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4
// The area of the triangle is 33.6

import std;

double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    std::cout << "Enter three points for a triangle(x1, y1, x2, y2, x3, y3): ";
    std::string line;
    std::getline(std::cin, line);

    // Replace commas with spaces so >> can split on them
    for (char& c : line) {
        if (c == ',') c = ' ';
    }

    std::istringstream iss(line);
    double x1, y1, x2, y2, x3, y3;
    iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double side1 = distance(x1, y1, x2, y2);
    double side2 = distance(x2, y2, x3, y3);
    double side3 = distance(x1, y1, x3, y3);

    double s = (side1 + side2 + side3) / 2;
    double area = std::sqrt(s * (s - side1) * (s - side2) * (s - side3));

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "The area of the triangle is " << area << '\n';

    return 0;
}
