#pragma once
#include <bits/stdc++.h>
#include "clsDblLinkedLIst.h"
#include "clsDate.h"

using namespace std;


class clsQueueLine
{
  struct stTicket
  {
    string code;
    string DateTime;
    int WaitingClients;
    int ServedClients;
    int servingTime;
  };

private:
  string _prefix;
  int _serving_time;
  int _waiting_clients;
  int _served_clients;
  static int _number;
  queue<stTicket> tickets;
  queue<stTicket>_copy_tickets;
  clsDblLinkedList<string> codes;

  void _PrintHeader()
  {
    string prefix = "Prefix: " + _prefix;
    string servedclients = "Served Clients = " + to_string(_served_clients) + " Client(s)";
    string waitingClients = "Waiting Clients = " + to_string(_waiting_clients) + " Client(s)";
    cout << "---------------------------------\n";
    cout << setw(35) << prefix << endl;
    cout << setw(35) << clsDate::getNowDateAndTime() << endl;
    cout << setw(35) << servedclients << endl;
    cout << setw(35) << waitingClients << endl;
    cout << "---------------------------------\n";
  }

  void _PrintTicket(stTicket ticket)
  {
    string servedclients = "Served Clients = " + to_string(ticket.ServedClients) + " Client(s)";
    string waitingClients = "Waiting Clients = " + to_string(ticket.WaitingClients) + " Client(s)";
    string timeToServe = "Time to serve you: " + to_string(ticket.servingTime) + " Minute(s)";

    cout << "---------------------------------\n";
    cout << setw(35) << ticket.code << endl;
    cout << setw(35) << ticket.DateTime << endl;
    cout << setw(35) << servedclients << endl;
    cout << setw(35) << waitingClients << endl;
    cout << setw(35) << timeToServe << endl;
    cout << "---------------------------------\n";
  }

  void _PrintTicketsLineLTR(bool firstTime = true)
  {
    if (_copy_tickets.empty())
      return;
    
    string code = (_copy_tickets.front()).code;
    
    _copy_tickets.pop();
    
    _PrintTicketsLineLTR(false);

    cout << code;
    
    if (!firstTime)
      cout << "-> ";
    else
      cout << endl;
  }

public:
  clsQueueLine(string prefix, int servingTime)
  {
    _prefix = prefix;
    _serving_time = servingTime;
    _waiting_clients = 0;
    _served_clients = 0;
    _number = 0;
  };

  void IssueTicket()
  {
    ++_number;

    stTicket ticket;
    ticket.code = _prefix + to_string(_number);
    ticket.DateTime = clsDate::getNowDateAndTime();
    ticket.ServedClients = _served_clients;
    ticket.WaitingClients = _waiting_clients;
    ticket.servingTime = _serving_time * _waiting_clients;

    tickets.push(ticket);
    _copy_tickets.push(ticket);
    ++_waiting_clients;
  }

  void PrintAllTickets()
  {
    while (!_copy_tickets.empty())
    {
      _PrintTicket(_copy_tickets.front());
     _copy_tickets.pop();
    }
    _copy_tickets = tickets;
  }

  void PrintTicketsLineRTL()
  {
    while (!_copy_tickets.empty())
    {
      cout << (_copy_tickets.front()).code;
      if ((_copy_tickets.front()).code != (_copy_tickets.back()).code)
        cout << "-> ";
      else
        cout << endl;
     _copy_tickets.pop();
    }
    _copy_tickets = tickets;
  }

  void PrintInfo() {
    _PrintHeader();
  }

  void ServeNextClient() {
    tickets.pop();
    --_waiting_clients;
    ++_served_clients;
  }

  void PrintTicketsLineLTR() {
    _PrintTicketsLineLTR();
    _copy_tickets = tickets;
  }

};

int clsQueueLine::_number = 0;
