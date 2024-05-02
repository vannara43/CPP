// Vannara Thong CSC5 Chapter 3, p.143, #5
//
/**************************************************************
 *
 * BOX OFFICE
 * ____________________________________________________________
 * This program will Displays the details of a movie's box
 * office profits.
 *
 *
 * Computation is based on the formula:
 * grossBoxOfficeProfit = Adult and Child Ticket * Cost of each
 * netBoxOfficeProfit = Gross Income * 20 Percent
 * amountPaidToDistributor = Gross Income - Net Income
 * ____________________________________________________________
 * INPUT
 * nameOfMovie               : The name of the movie.
 * adultTickets              : The number of adult tickets sold.
 * childTickets              : The number of child tickets sold.
 * TICKET_COST_ADULT         : The cost of an adult ticket.
 * TICKET_COST_CHILD         : The cost of a child ticket.
 *
 *
 * OUTPUT
 * grossBoxOfficeProfit      : The total gross revenue generated
 * netBoxOfficeProfit        : The net revenue generated
 * amountPaidToDistributor   : The amount paid to the distributor
 *
 **************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    /* A movie theater only keeps a percentage of the revenue earned from ticket sales. The remainder goes to the movie distributor. Write a program that calculates a theater's gross and net box office profit for a night. The program should ask for the name of the movie, and how many adult and child tickets were sold. (The price of an adult ticket is $6.00 and a child s ticket is $3.00.) It should display a report similar to:

    Movie Name: Wheels of Fury
    Adult Tickets Sold: 382
    Child Tickets Sold: 127
    Gross Box Of ce Pro t: $ 2673.00
    Net Box Of ce Pro t: $ 534.60
    Amount Paid to Distributor: $ 2138.40*/

    // VARIABLE DECLARATION
    string nameOfMovie;             // The name of the movie.
    int adultTickets;               // The number of adult tickets sold.
    int childTickets;               // The number of child tickets sold.
    float TICKET_COST_ADULT = 6.00; // The cost of an adult ticket.
    float TICKET_COST_CHILD = 3.00; // The cost of a child ticket.
    double grossBoxOfficeProfit;    // The total gross revenue generated
    double netBoxOfficeProfit;      // The net revenue generated
    double amountPaidToDistributor; // The amount paid to the distributor

    // INPUT VALUES
    cout << "Title Of The Movie: ";
    getline(cin, nameOfMovie); // The variable to store the title of the movie
    cout << "How many Adult ticket? ";
    cin >> adultTickets; // The variable to store the adultTickets
    cout << "How many Child ticket? ";
    cin >> childTickets; // The variable to store the childTickets

    // SINGLE SPACE
    cout << "\n";

    // CALCULATION
    grossBoxOfficeProfit = ((adultTickets * TICKET_COST_ADULT) + (childTickets * TICKET_COST_CHILD));
    netBoxOfficeProfit = (grossBoxOfficeProfit * .20);
    amountPaidToDistributor = (grossBoxOfficeProfit - netBoxOfficeProfit);

    // OUTPUT DISPLAY
    cout << "Movie Name: " << ("\"" + nameOfMovie + "\"") << endl;
    cout << "Adult Tickets Sold: " << adultTickets << endl;
    cout << "Child Tickets Sold: " << childTickets << endl;
    cout << setprecision(2) << fixed << showpoint;
    cout << "Gross Box Office Profit: $" << grossBoxOfficeProfit << endl;
    cout << "Net Box Office Profit: $" << netBoxOfficeProfit << endl;
    cout << "Amount Paid to Distributor: $" << amountPaidToDistributor << endl;

    return 0;
}