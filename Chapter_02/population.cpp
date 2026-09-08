// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.

// The program prints the projected population at the end of each of
// the next five years.


import std;
using namespace std;

int main() {
    // Starting population given in the problem.
    constexpr int64_t current_population = 312'032'486;

    // Seconds in one non-leap year: 365 days * 24 h * 60 min * 60 s.
    constexpr int64_t seconds_per_year = 365LL * 24 * 60 * 60;  // 31,536,000

    // How many of each event occur in one full year.
    // Integer division keeps counts as whole people.
    constexpr int64_t births_per_year     = seconds_per_year / 7;   // +births
    constexpr int64_t deaths_per_year     = seconds_per_year / 13;  // -deaths
    constexpr int64_t immigrants_per_year = seconds_per_year / 45;  // +immigrants

    // Net change applied once per year:
    //   population grows by births and immigrants, shrinks by deaths.
    constexpr int64_t net_change_per_year =
        births_per_year - deaths_per_year + immigrants_per_year;

    // Show the rates so the calculation is easy to audit.
    cout << "Assumptions\n";
    cout << format("  Seconds in a year      : {}\n", seconds_per_year);
    cout << format("  Births per year        : {}\n", births_per_year);
    cout << format("  Deaths per year        : {}\n", deaths_per_year);
    cout << format("  Immigrants per year    : {}\n", immigrants_per_year);
    cout << format("  Net change per year    : {:+}\n\n", net_change_per_year);

    cout << format("Current population       : {}\n\n", current_population);
    cout << "Projected population for the next five years:\n";

    // Start from the current figure and add the same net change each year.
    int64_t population = current_population;

    for (int year = 1; year <= 5; ++year) {
        population += net_change_per_year;
        cout << format("  Year {}: {}\n", year, population);
    }

    return 0;
}
