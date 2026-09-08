// Write a program that prompts the user to enter a weight in pounds and height in inches and
// then displays the BMI. Note that one pound is 0.45359237 kilograms and one inch is
// 0.0254 meters. Listing 4.6 gives the program.

// Conditions
// Below 18.5 Underweight
// 18.5–24.9 Normal
// 25.0–29.9 Overweight
// Above 30.0 Obese

// Enter weight in pounds:
// Enter Weight in pounds: 146
// Enter height in inches: 70
// BMI is 20.95
// Normal

// Write a program that prompts the user to enter a weight in pounds and height in inches and
// then displays the BMI. Note that one pound is 0.45359237 kilograms and one inch is
// 0.0254 meters. Listing 4.6 gives the program.

// Conditions
// Below 18.5 Underweight
// 18.5-24.9 Normal
// 25.0-29.9 Overweight
// Above 30.0 Obese

// Enter weight in pounds:
// Enter Weight in pounds: 146
// Enter height in inches: 70
// BMI is 20.95
// Normal

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