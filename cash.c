#include <stdio.h>
#include <cs50.h>

int get_cents(void);
int calculate_quarters(int n);
int calculate_dimes(int n);
int calculate_nickels(int n);
int calculate_pennies(int n);

int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;

int quarters_amount = 0;
int dimes_amount = 0;
int nickels_amount = 0;
int pennies_amount = 0;

int total_coins;

int main(void)
{
    int change_owed = get_cents();

    if (change_owed >= quarter)
    {
        calculate_quarters(change_owed);
    }
    else if (change_owed >= dime)
    {
        calculate_dimes(change_owed);
    }
    else if (change_owed >= nickel)
    {
        calculate_nickels(change_owed);
    }
    else
    {
        calculate_pennies(change_owed);
    }

    total_coins = (quarters_amount + dimes_amount + nickels_amount + pennies_amount);

    string quarter = (quarters_amount > 1 || quarters_amount == 0) ? "quarters" : "quarter";
    string dime = (dimes_amount > 1 || dimes_amount == 0) ? "dimes" : "dime";
    string nickel = (nickels_amount > 1 || nickels_amount == 0) ? "nickels" : "nickel";
    string penny = (pennies_amount > 1 || pennies_amount == 0) ? "pennies" : "penny";

    return printf(" %i %s, %i %s, %i %s, %i %s\n Total coins: %i\n", quarters_amount, quarter, dimes_amount, dime, nickels_amount, nickel, pennies_amount, penny, total_coins);
}

int get_cents(void)
{
    int cents;

    do
    {
        cents = get_int("Change owed: ");

    } while (cents < 0);

    return cents;
}

int calculate_quarters(int n)
{
    int remainder = n;

    if (n == quarter)
    {
        quarters_amount = 1;
        return quarters_amount;
    }

    else if ((n % quarter) == 0)
    {
        quarters_amount = n / quarter;
        return quarters_amount;
    }

    if (n > quarter)
    {
        do
        {
            remainder -= quarter;
            quarters_amount += 1;

        } while (remainder > quarter);

        if (remainder >= dime)
        {
            calculate_dimes(remainder);
        }
        else if (remainder >= nickel)
        {
            calculate_pennies(remainder);
        }
        else if (remainder >= penny)
        {
            calculate_pennies(remainder);
        }

        return quarters_amount;
    }

    return quarters_amount;
}

int calculate_dimes(int n)
{
    int remainder = n;

    if (n == dime)
    {
        dimes_amount = 1;
        return dimes_amount;
    }

    else if ((n % dime) == 0)
    {
        dimes_amount = n / dime;
        return dimes_amount;
    }

    if (n > dime)
    {
        do
        {
            remainder -= dime;
            dimes_amount += 1;

        } while (remainder > dime);

        if (remainder >= nickel)
        {
            calculate_nickels(remainder);
        }
        else if (remainder >= penny)
        {
            calculate_pennies(remainder);
        }
    }
    return dimes_amount;
}

int calculate_nickels(int n)
{
    int remainder = n;

    if (n == nickel)
    {
        nickels_amount = 1;
        return nickels_amount;
    }

    else if ((n % nickel) == 0)
    {
        nickels_amount = n / nickel;
        return nickels_amount;
    }

    if (n > nickel)
    {
        do
        {
            remainder -= nickel;
            nickels_amount += 1;

        } while (remainder > nickel);

        if (remainder > 0)
        {
            calculate_pennies(remainder);
        }
        else
        {
            return nickels_amount;
        }
    }
    return nickels_amount;
}

int calculate_pennies(int n)
{
    int remainder = n;

    if (n == penny)
    {
        pennies_amount = 1;
        return pennies_amount;
    }

    else if ((n % penny) == 0)
    {
        pennies_amount = n / penny;
        return pennies_amount;
    }

    if (n > penny)
    {
        do
        {
            remainder -= penny;
            pennies_amount += 1;

        } while (remainder > penny);

        return pennies_amount;
    }

    return pennies_amount;
}
