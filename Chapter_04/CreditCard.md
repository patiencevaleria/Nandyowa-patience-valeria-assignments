# CreditCard.cpp`

This program checks whether an integer the user types is a plausible credit-card number. It does **not** contact a bank or payment network. It only applies the usual classroom rules: length, issuer prefix, and the Luhn checksum.

## What the program does

1. Prompt for a card number and read it as a `long long`.
2. Reject the number if it does not have 13–16 digits.
3. Reject the number if it does not start with one of these prefixes:
   - `4` — Visa
   - `5` — MasterCard
   - `37` — American Express
   - `6` — Discover
4. Run the Luhn check. The number is treated as valid only if that checksum ends in 0.
5. Print either `<number> is valid.` or `<number> is invalid.`

Example interaction:

```text
Enter a credit card number as an integer: 4388576018402626
4388576018402626 is invalid.
```

A known Luhn-passing test number such as `4388576018410707` would be reported as valid (16 digits, prefix 4, checksum divisible by 10).

## How the pieces fit

`main` only handles input and output. All rules live in `isValid`:

```cpp
bool isValid(long long number) {
    int totalDigits = getSize(number);
    if (totalDigits < 13 || totalDigits > 16) return false;
    if (!prefixMatched(number, 4) && !prefixMatched(number, 5) &&
        !prefixMatched(number, 37) && !prefixMatched(number, 6)) return false;
    return (sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0;
}
```

The three checks are independent. Failing any one of them makes the card invalid.

## The Luhn checksum

Positions are counted from the **right**, starting at 1 for the rightmost digit.

- Odd positions (1st, 3rd, 5th, … from the right) are added as they are.
- Even positions (2nd, 4th, 6th, … from the right) are doubled. If a doubled value is 10 or more, its digits are added together (for example, `7 * 2 = 14` becomes `1 + 4 = 5`).
- The card passes if the total of those two sums is divisible by 10.

`sumOfOddPlace` walks the number two digits at a time and keeps the current ones digit, so it always sums the rightmost remaining digit:

```cpp
int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;   // rightmost digit (odd place from the right)
        number /= 100;        // drop that digit and the next one
    }
    return sum;
}
```

`sumOfDoubleEvenPlace` first drops the rightmost digit, then doubles the new rightmost digit, folds it with `getDigit`, and drops that digit as well. That selects every even place from the right:

```cpp
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        number /= 10;                     // skip the odd-place digit
        int digit = (number % 10) * 2;    // double the even-place digit
        sum += getDigit(digit);
        number /= 10;                     // drop the digit just processed
    }
    return sum;
}
```

`getDigit` is the “add the two digits if the product is at least 10” step:

```cpp
int getDigit(int number) {
    if (number < 10) return number;
    return number / 10 + number % 10;
}
```

Worked fragment for `4388576018402626`, processing from the right:

| Digit (right to left) | Place | Treatment | Contribution |
| --- | --- | --- | --- |
| 6 | odd | as-is | 6 |
| 2 | even | 2 × 2 = 4 | 4 |
| 6 | odd | as-is | 6 |
| 2 | even | 2 × 2 = 4 | 4 |
| 0 | odd | as-is | 0 |
| 4 | even | 4 × 2 = 8 | 8 |
| 8 | odd | as-is | 8 |
| 1 | even | 1 × 2 = 2 | 2 |
| 0 | odd | as-is | 0 |
| 6 | even | 6 × 2 = 12 → 1+2 | 3 |
| 7 | odd | as-is | 7 |
| 5 | even | 5 × 2 = 10 → 1+0 | 1 |
| 8 | odd | as-is | 8 |
| 8 | even | 8 × 2 = 16 → 1+6 | 7 |
| 3 | odd | as-is | 3 |
| 4 | even | 4 × 2 = 8 | 8 |

Odd-place sum is 38. Even-place sum is 37. Total is 75, and `75 % 10 != 0`, so the number is invalid.

## Prefix and length helpers

`getSize` counts digits by repeatedly dividing by 10. Zero has size 0, which is fine here because a real card number is never 0.

`getPrefix(number, k)` returns the first `k` digits. It divides the number by 10 exactly `size - k` times, which strips the trailing digits and leaves the leading ones.

`prefixMatched(number, d)` asks whether the card starts with `d`. It uses the digit count of `d` as `k`, so `4` checks one digit, `5` checks one digit, `37` checks two digits, and `6` checks one digit.

## Function map

| Function | Role |
| --- | --- |
| `main` | Read the number and print valid or invalid. |
| `isValid` | Apply length, prefix, and Luhn rules. |
| `sumOfDoubleEvenPlace` | Double every second digit from the right and sum the folded results. |
| `getDigit` | Return `n` if `n < 10`, otherwise the sum of its two digits. |
| `sumOfOddPlace` | Sum every other digit from the right, starting with the last digit. |
| `prefixMatched` | True if the card starts with the given prefix. |
| `getSize` | Number of digits. |
| `getPrefix` | Leading `k` digits of the number. |

## Limits of this implementation

- Input is a `long long`. A number longer than what `long long` can hold cannot be entered correctly, and leading zeros are impossible because the value is an integer.
- Non-numeric input is not handled. If `cin` fails, `cardNumber` is left uninitialized or unchanged and the result is not meaningful.
- Issuer rules are simplified. Real Visa, MasterCard, Amex, and Discover numbers use tighter length and prefix ranges than “starts with 4, 5, 37, or 6 and has 13–16 digits.”
- Passing this check only means the number has the right shape and checksum. It does not mean the card exists or can be charged.
