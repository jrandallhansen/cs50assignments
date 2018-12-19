#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    //Intiliaze longlong user_ccnumber for user input
    long long user_ccnumber;

    //Prototype count_digits function
    int count_digits(long long x);

    //Prototype sum_digits function
    int sum_digits(int c);

    //Prototype check_sum function
    int check_sum(long long d);

    //Prototype first_two_digits function
    int first_two_digits(long long a);

    //Receive a valid positive long long input from user
    do
    {
        user_ccnumber = get_long_long("Credit Card Number: ");
    }
    while (user_ccnumber < 0);
    //Initialize integer variable to hold user_ccnumber digit count
    int usercc_digitcount = count_digits(user_ccnumber);
    //Check user_ccnumber length and check_sum status. Either print invalid or continue validating
    if (usercc_digitcount < 13 || usercc_digitcount > 16 || usercc_digitcount == 14 || check_sum(user_ccnumber) != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        //use switch statement to identify the card issuer based on first_two_digits and print correct statement
        int first_two = first_two_digits(user_ccnumber);
        switch (first_two)
        {
            case 34:
            case 37:
                printf("AMEX\n");
                break;
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                printf("MASTERCARD\n");
                break;
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
                printf("VISA\n");
                break;
            case -99:
                printf("INVALID\n");
                break;
            default:
                printf("INVALID\n");
                break;
        }
    }
    //return 0 to follow instructions
    return 0;
}

//Define count_digits which takes a long long and returns an integer representing how many digits the input value contains
int count_digits(long long x)
{
    int digits = 0;
    while (x > 0)
    {
        x = x / 10;
        digits ++;
    }
    return digits;
}

//Define first_two_digits to return first two digits of user_ccnumber or -99 if the number is an invalid length
int first_two_digits(long long a)
{
    int two_digits;
    if (count_digits(a) == 13)
    {
        two_digits = a / 100000000000;
    }
    else if (count_digits(a) == 15)
    {
        two_digits = a / 10000000000000;
    }
    else if (count_digits(a) == 16)
    {
        two_digits = a / 100000000000000;
    }
    else
    {
        two_digits = -99;
    }
    return two_digits;
}

//Define sum_digits to add digits of a given integer and return the sum
int sum_digits(int c)
{
    int sum = 0;
    while (c > 0)
    {
        sum += (c % 10);
        c /= 10;
    }
    return sum;
}

//Define check_sum to split input long long into array of integers, double alternating integer values, and then sum all digits. Return the sum modulo 10 and only "0" is a valid return value
int check_sum(long long d)
{
    //initialize integer for array length equal to the number of digits from input long long
    int length = count_digits(d);
    //initialize array to hold all digits from input long long
    int arr[length];
    //loop over arr to assign each ascending position to the last digit in user_ccnumber then delete the last digit in input long long
    for (int i = 0; i < length; i++)
    {
        arr[i] = d % 10;
        d /= 10;
    }
    //loop over arr by iterations of two and double each integer starting on the 1 position
    for (int j = 1; j < length; j += 2)
    {
        arr[j] = arr[j] * 2;
    }
    //initialize an integer to hold the arr_sum
    int arr_sum = 0;
    //loop over arr to add each digit to the arr_sum
    for (int k = 0; k < length ; k++)
    {
        arr_sum += sum_digits(arr[k]);
    }
    //return arr_sum modulo 10
    return arr_sum % 10;
}