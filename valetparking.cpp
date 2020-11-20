#include "valetparking.h"

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

ValetParking::~ValetParking()
{}

// return the maximum number of cars that all stalls can accommodate
size_t ValetParking::TotalStallSpaces() {
  return _numberofstalls * _stallcapacity;
}

// return the number of cars parked in all the stalls
size_t ValetParking::CarsInStalls() {
  size_t totalcars = 0;
  for(const auto& s : _parkingstall) {
    totalcars += s.size();
  }
  return totalcars;
}

// return  number of cars waiting in checkout line to pay before exiting the lot
size_t ValetParking::CarsInCheckOut() {
  return _checkout->size();
}

// return the number of available parking spaces in all the stalls
size_t ValetParking::AvailableStallSpaces() {
  size_t availablespaces = 0;
  for(const auto& s : _parkingstall) {
    int space = _stallcapacity-s.size();
    availablespaces += space;
  }
  return availablespaces;
}

// return the total amount based on the number of tickets issued
double ValetParking::TotalSales() {
  return _currentticket * _fee;
}

// remove and return the ticket# of car at front of the checkout queue,
// and the fee is collected.
size_t ValetParking::Pay() {
  if(_checkout->empty()) {
    return 0;
  }
  _paid += _fee;
  size_t ticketNo = _checkout->front();
  _checkout->pop();
  return ticketNo;
}

// return the total amount customers have paid so far
// based on the number of cars exited the lot.
double ValetParking::TotalPaid() {
  return _paid;
}

// return true if all stalls and checkout queue are empty
bool ValetParking::ParkingEmpty() {
  if(!(StallEmpty() && QueueEmpty())) {
    return false;
  }
  return true;
}

// return true if all stalls and checkout queue are full
bool ValetParking::ParkingFull() {
  if(!(StallFull() && QueueFull())) {
    return false;
  }
  return true;
}

// return true if the checkout queue is empty
bool ValetParking::QueueEmpty() {
  if(!(_checkout->empty())) {
    return false;
  }
  return true;
}

// return true if the checkout queue is full
bool ValetParking::QueueFull() {
  if(!(_checkout->size() == _queuecapacity)) {
    return false;
  }
  return true;
}

// return true if all stalls are empty
bool ValetParking::StallEmpty() {
  for(const auto& s : _parkingstall) {
    if(!s.empty()) {
      return false;
    }
  }
  return true;
}

// return true if all stalls are full
bool ValetParking::StallFull() {
  for(const auto& s : _parkingstall) {
    if(s.size() != _stallcapacity) {
      return false;
    }
  }
  return true;
}

// return the next ticket number to issue to customer
size_t ValetParking::GetNextTicket() {
  return ++_currentticket;
}

// on success return stall# (index-1 base), on failure return 0.
size_t ValetParking::CheckIn() {
 size_t ticketNo = GetNextTicket();
 for (size_t i = 0; i < _numberofstalls; ++i) {
   if (_parkingstall[i].size() == _stallcapacity) {
     continue;
   }
   _parkingstall[i].push(ticketNo);
   return i + 1;
 }
 return 0;
}

// return the stall number (index-1 base) in which the ticket number resides
size_t ValetParking::StallNumber(size_t ticket) {
  for (size_t i = 0; i < _numberofstalls; ++i) {
    auto sn = _parkingstall[i];
    while (!sn.empty()) {
        size_t ticketNumber = sn.top();
        if (ticketNumber == ticket) {
          return i + 1;
        }
        sn.pop();
    }
  }
  return 0;
}

// Retrieve the ticket# from the stall
// and place the ticket in the checkout queue.
// On success return true.
bool ValetParking::CheckOut( size_t stallnumber, size_t ticket) {
  if (!QueueFull()) {
  _parkingstall[stallnumber - 1].pop();
  _checkout->push(ticket);
  return true;
  }
  return false;
}
