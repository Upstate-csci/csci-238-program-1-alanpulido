/********
 Author:
 Program: Money class - program assignment #1
 Due Date:
 Purpose:
 ********/
#include "money.h"

// convert current currency values to a string
string Money::toString() {
    return "";
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {
    stringstream ss;

    ss << "$" << left << setfill('0') << setw(4) << amount;
    return ss.str();
}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    //takes in data
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;
    
    //assigns a total value of all the cents
    int coins = (quarters + dimes + nickels + cents);
    
    //math to make sure cent never go past 99
    if (coins >= 100)
    {
        coins -= 100;
        ones++;
    }
    //more fun math
    total = (hundreds*100.0) + (tens*10.0) + (fives*5.0) + ones + (quarters*0.25) + (dimes*0.10) + (nickels*0.05) + (cents*0.01);
        
    //make a stringstream i will return
        stringstream x;
        x << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << cents << " pennies = $" << total;
    return x.str();
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {

    //take in data
    cin >> total;
    
    //have a raw or pure or untampered total
    double totalFirst = total;

    // math that assigns quantaties to bill denominations
    hundreds = total / 100;
    total -= (hundreds * 100.0);
    tens = total / 10;
    total -= (tens*10.0);
    fives = total / 5;
    total -= (fives*5.0);
    ones = total / 1;
    total -= (ones * 1);
    quarters = total / 0.25;
    total -= (total * 0.25);
    dimes = total / 0.10;
    total -= (dimes * 0.10);
    nickels = total / 0.05;
    total -= (nickels * 0.05);
    cents = total / 0.01;
    total -= (cents*0.01);
    
    //make a stringstream and give value
    stringstream x;
    x << totalFirst << " = " << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << cents << " pennies ";
        return x.str();
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
  return "";
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
  return "";
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    
    //declare variables that will be needed
    float cp;
    float tc;
    int inHundreds;
    int inTens;
    int inFives;
    int inOnes;
    int inQuarters;
    int inDimes;
    int inNickels;
    int inCents;

    //take in data
    cin >> inHundreds >> inTens >> inFives >> inOnes >> inQuarters >> inDimes >> inNickels >> inCents >> tc;
    
    //cp is Customer Payment
    cp = (inHundreds * 100) + (inTens*10) + (inFives*5) + (inOnes*1) + (inQuarters*0.25) + (inDimes*0.10) + (inNickels*0.05) + (inCents*0.01);
    
    //changebk is the change back
    float changebk = cp - tc;
    //og is the Original change before alterations
    float og = changebk;

    //math that assigns values to bill denominations
    hundreds = changebk / 100;
    changebk -= (hundreds * 100);
    tens = changebk / 10;
    changebk -= (tens * 10);
    fives = changebk / 5;
    changebk -= (fives * 5);
    ones = changebk / 1;
    changebk -= (ones * 1);
    quarters = changebk / 0.25;
    changebk -= (quarters * 0.25);
    dimes = changebk / 0.10;
    changebk -= (dimes * 0.10);
    nickels = changebk / 0.10;
    changebk -= (nickels * 0.05);
    cents = changebk / 0.01;
    changebk -= (cents * 0.01);

    //make a stringstream, assign it a string value, return it.
    stringstream x;
    x << "change back on " << inHundreds << " hundreds " << inTens << " tens " << inFives << " fives " << inOnes << " ones " << inQuarters << " quarters " << inDimes << " dimes " << inNickels << " nickels " << inCents << " pennies for purchase of $" << tc << " is " << og<< " which is " << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << cents << " pennies ";
    return x.str();
}
