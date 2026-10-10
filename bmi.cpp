import std;

int main() {
    const double KILOGRAMS_PER_POUND = 0.45359237;
    const double METERS_PER_INCH = 0.0254;

    double weightInPounds, heightInInches;

    std::cout << "Enter weight in pounds: ";
    std::cin >> weightInPounds;

    std::cout << "Enter height in inches: ";
    std::cin >> heightInInches;

    double weightInKilograms = weightInPounds * KILOGRAMS_PER_POUND;
    double heightInMeters = heightInInches * METERS_PER_INCH;
    double bmi = weightInKilograms / (heightInMeters * heightInMeters);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "BMI is " << bmi << '\n';

    if (bmi < 18.5) {
        std::cout << "Underweight" << '\n';
    }
    else if (bmi < 25.0) {
        std::cout << "Normal" << '\n';
    }
    else if (bmi < 30.0) {
        std::cout << "Overweight" << '\n';
    }
    else {
        std::cout << "Obese" << '\n';
    }

    return 0;
}