import std;
using namespace std;

// Returns the day suffix: st, nd, rd, or th
string getDaySuffix(int day) {
    if (day >= 11 && day <= 13) return "th";
    switch (day % 10) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int day = ltm->tm_mday;
    int year = 1900 + ltm->tm_year;
    string month = months[ltm->tm_mon];

    return to_string(day) + getDaySuffix(day) + " " + month + " " + to_string(year);
}

int main() {
    string firstName, lastName, program, academicYear;

    cout << "===== Makerere University Admissions =====" << endl;
    cout << "Enter your first name: ";
    getline(cin, firstName);

    cout << "Enter your last name: ";
    getline(cin, lastName);

    cout << "Enter your study program (e.g. Bachelor of Science in Computer and Communication Engineering): ";
    getline(cin, program);

    cout << "Enter academic year (e.g. 2027/2028): ";
    getline(cin, academicYear);

    string fullName = firstName + " " + lastName;
    string date = getCurrentDate();

    cout << "\n\n";
    cout << "Date: " << date << endl;
    cout << "To: " << fullName << "," << endl;
    cout << "Dear " << firstName << "," << endl << endl;

    cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University" << endl;
    cout << "Admissions Board has approved your application for admission to the" << endl;
    cout << academicYear << " academic year." << endl << endl;

    cout << "You have been offered a place for the following course:" << endl;
    cout << "PROGRAM: " << program << endl << endl;

    cout << "As a student of Makerere University, you will be part of a historic" << endl;
    cout << "institution dedicated to academic excellence and innovation. Please ensure" << endl;
    cout << "that you report to the Academic Registrar's office with your original" << endl;
    cout << "academic documents for verification during the orientation week." << endl << endl;

    cout << "We look forward to welcoming you to the Makerere University." << endl << endl;

    cout << "Yours sincerely," << endl;
    cout << "John Doe" << endl;
    cout << "Registrar" << endl;

    return 0;
}
