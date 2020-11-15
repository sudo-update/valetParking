#include "valetparking.h"

// ATTENTION STUDENTS:
// THE CONSTRUCTORS ARE ALREADY COMPLETED.
// YOU NEED TO COMPLETE THE DESTRUCTOR AND ALL OF THE REMAINING FUNCTIONS BELOW.

// CONSTRUCTORS - ALREADY COMPLETE
ValetParking::ValetParking()
  : _numberofstalls( 1 ),
    _stallcapacity( 1 ),
    _parkingstall(_numberofstalls, std::stack<size_t>() ),
    _queuecapacity( 1 ),
    _checkout(std::make_unique<std::queue<size_t>>()),
    _currentticket( 0 ),
    _fee( 5.0 ),
    _paid( 0.0 )
{}

ValetParking::ValetParking( size_t numberofstalls,
			    size_t stallcapacity,
			    size_t queuecapacity,
			    size_t ticketnumber,
			    double fee )
  : _numberofstalls( numberofstalls ),
    _stallcapacity( stallcapacity ),
    _parkingstall(_numberofstalls, std::stack<size_t>() ),
    _queuecapacity( queuecapacity ),
    _checkout(std::make_unique<std::queue<size_t>>()),
    _currentticket( ticketnumber ),
    _fee( fee ),
    _paid( 0.0 )
{}

// DESTRUCTOR - ALREADY COMPLETE
ValetParking::~ValetParking()
{}

size_t ValetParking::TotalStallSpaces()
// return the maximum number of cars that all stalls can accommodate
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0;
}

size_t ValetParking::CarsInStalls()
// return the number of cars parked in all the stalls
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0;
}

size_t ValetParking::CarsInCheckOut()
// return the number of cars waiting in checkout line to pay before exiting the lot.
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0;
}

size_t ValetParking::AvailableStallSpaces()
// return the number of available parking spaces in all the stalls
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0;
}

double ValetParking::TotalSales()
// return the total amount based on the number of tickets issued
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0.0;
}

size_t ValetParking::Pay()
// remove and return the ticket# of car at front of the checkout queue, and the fee is collected.
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0;
}

double ValetParking::TotalPaid()
// return the total amount customers have paid so far based on the number of cars exited the lot.
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0.0;
}

bool ValetParking::ParkingEmpty()
// return true if all stalls and checkout queue are empty
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return false;
}

bool ValetParking::ParkingFull()
// return true if all stalls and checkout queue are full
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return false;
}

bool ValetParking::QueueEmpty()
// return true if the checkout queue is empty
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return false;
}

bool ValetParking::QueueFull()
// return true if the checkout queue is full
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return false;
}

bool ValetParking::StallEmpty()
// return true if all stalls are empty
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return false;
}

bool ValetParking::StallFull()
// return true if all stalls are full
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return false;
}

size_t ValetParking::GetNextTicket()
// return the next ticket number to issue to customer
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0;
}

size_t ValetParking::CheckIn()
// on success return stall# (index-1 base), on failure return 0.
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0;
}

size_t ValetParking::StallNumber( size_t ticket)
// return the stall number (index-1 base) in which the ticket number resides
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0;
}

bool ValetParking::CheckOut( size_t stallnumber, size_t ticket) 
// Retrieve the ticket# from the stall and place the ticket in the checkout queue.
// On success return true.
{
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return false;
}
