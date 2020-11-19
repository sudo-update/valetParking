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
  return _numberofstalls * _stallcapacity;
}

size_t ValetParking::CarsInStalls()
// return the number of cars parked in all the stalls
{
  size_t totalcars = 0;
  for(const auto& s : _parkingstall) {
    totalcars += s.size();
  }
  return totalcars;
}

size_t ValetParking::CarsInCheckOut()
// return the number of cars waiting in checkout line to pay before exiting the lot.
{
  return _checkout->size();
}

size_t ValetParking::AvailableStallSpaces()
// return the number of available parking spaces in all the stalls
{
  size_t availablespaces = 0;
  for(const auto& s : _parkingstall){
    int space = _stallcapacity-s.size();
    availablespaces += space;
  }
  return availablespaces;
}

double ValetParking::TotalSales()
// return the total amount based on the number of tickets issued
{
  return _currentticket * _fee;
}

size_t ValetParking::Pay()
// remove and return the ticket# of car at front of the checkout queue, and the fee is collected.
{
  if(_checkout->empty()){
    return 0;
  }
  _paid += _fee;
  size_t ticketNo = _checkout->front();
  _checkout->pop();
  return ticketNo;
}

double ValetParking::TotalPaid()
// return the total amount customers have paid so far based on the number of cars exited the lot.
{
  return _paid;
}

bool ValetParking::ParkingEmpty()
// return true if all stalls and checkout queue are empty
{
  if(!(StallEmpty() && QueueEmpty())){
    return false;
  }
  return true;
}

bool ValetParking::ParkingFull()
// return true if all stalls and checkout queue are full
{
  if(!(StallFull() && QueueFull())){
    return false;
  }
  return true;
}

bool ValetParking::QueueEmpty()
// return true if the checkout queue is empty
{
  if(!(_checkout->empty())){
    return false;
  }
  return true;
}

bool ValetParking::QueueFull()
// return true if the checkout queue is full
{
  if(!(_checkout->size() == _queuecapacity)){
    return false;
    }
  return true;
}

bool ValetParking::StallEmpty()
// return true if all stalls are empty
{
  for(const auto& s : _parkingstall){
    if(!s.empty()){
      return false;
    }
  }
  return true;
}

bool ValetParking::StallFull()
// return true if all stalls are full
{
  for(const auto& s : _parkingstall){
    if(s.size() != _stallcapacity){
      return false;
    }
  }
  return true;
}

size_t ValetParking::GetNextTicket()
// return the next ticket number to issue to customer
{
  return ++_currentticket;
}

size_t ValetParking::CheckIn()
// on success return stall# (index-1 base), on failure return 0.
{
 size_t ticketNo = GetNextTicket();
 for (size_t i = 0; i < _numberofstalls; ++i){
   if (_parkingstall[i].size() == _stallcapacity){
     continue;
   }
     _parkingstall[i].push(ticketNo);
     return i + 1;
 }
 return 0;
}

size_t ValetParking::StallNumber(size_t ticket)
// return the stall number (index-1 base) in which the ticket number resides
{
  for (size_t i = 0; i < _numberofstalls; ++i){
    auto sn = _parkingstall[i];
    while (!sn.empty()){
        size_t ticketNumber = sn.top();
        if (ticketNumber == ticket){
          return i + 1;
        }
          sn.pop();
      }
  }
  return 0;
}

bool ValetParking::CheckOut( size_t stallnumber, size_t ticket)
// Retrieve the ticket# from the stall and place the ticket in the checkout queue.
// On success return true.
{
  if (!QueueFull()){
<<<<<<< HEAD
=======
    //_parkingstall[stallnumber-1].
>>>>>>> 0458febea74ae0ea562ee22d1b2ef9c0c1dac327
  _parkingstall[stallnumber-1].pop();
  _checkout->push(ticket);
    return true;
  }
  return false;
}
