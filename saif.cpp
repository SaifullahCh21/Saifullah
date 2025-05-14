#include"classlib.h"


#include <iostream>
#include <cstring>


// User class definitions


virtual bool  User::login(const string& u, const string& p)
{
    if (username == u && password == p)
    {
        return->this;
    }
    else
        cout << "-----You are invalid user-----";
}

User::~User() 
{
    cout << "-----Destructor working-----";
}

// Voter class definitions

void Voter::viewElections() 
{
    cout << "Displaying available elections...\n";
}

void Voter::castVote() 
{
    char press;
    if (!hasVoted) {
      cout << "-----Press the first letter of your party-----\n";
      if (press)//complete it according to your need
      {
          hasVoted = true;
      }
      else
          cout << " -----Press the valid button-----";
    }
    else {
       cout << "You have already voted.\n";
    }
}

void Voter::checkVoteStatus()
{
    if (hasVoted == true)
    {
        cout << "----VOTED----";
    }
    else
        cout << "----Not voted yet----";
}

//  administrator (aggregation)
Election* allElections[10];
int totalElections = 0;
// Administrator class definitions

void Administrator::createElection() 
{

    void Administrator::createElection() 
    {
        if (totalElections >= 10) {
            cout << "Maximum number of elections reached.\n";
            return;
        }

        int type;
        char title[50];
        cout << "---Enter election title: ---";
        cin.ignore();
        cin.getline(title, 50);

        cout << "-----Select election type (1 - Local, 2 - National, 3 - General): --------"<<endl;
        cin >> type;

        Election* election = nullptr;

        if (type == 1) {
            election = new LocalElection(title);
        }
        else if (type == 2) {
            election = new NationalElection(title);
        }
        else if (type == 3) {
            election = new GeneralElection(title);
        }
        else {
            cout << "----Invalid election type----\n";
            return;
        }

        int numCandidates;
        cout << "----Enter number of candidates (max 10):---- ";
        cin >> numCandidates;

        for (int i = 0; i < numCandidates; ++i) 
        {
            char cname[50], cparty[50];
            cout << "Enter name of candidate " << (i + 1) << ": ";
            cin.ignore();
            cin.getline(cname, 50);

            cout << "Enter party of candidate " << (i + 1) << ": ";
            cin.getline(cparty, 50);

            Candidate* c = new Candidate(cname, cparty);
            election->addCandidate(c);
        }

        cout << "Election created successfully.\n";
        allElections[totalElections++] = election;
    }

    void Administrator::addCandidate() {
        cout << "Adding candidate...\n";
    }

    void Administrator::viewResults() {
        cout << "Election Results:\n";
        for (int i = 0; i < totalElections; ++i) {
            cout << "Election " << i + 1 << ": " << allElections[i]->getTitle() << endl;
            allElections[i]->calculateResults();
            cout << "-----------------------------\n";
        }
    }


}

void Administrator::addCandidate() 
{
    cout << "Adding candidate...\n";
}

void Administrator::viewResults() 
{
    cout << "Viewing results...\n";
}


//CandidaTE CLASS
void Candidate::incrementVotes() 
{
    votes++;
}

int Candidate::getVoteCount() const 
{

    cout << "Total calculated votes till now: ";
    return votes;
}

void Candidate::getCandidateInfo() const 
{
    cout << "Name: " << name 
        << ", Party: " << party 
        << ", Votes: " << votes 
        << endl;
}

// Election class definitions
Election::Election(const char* t) {
    strcpy(title, t);
    isActive = false;
    candidateCount = 0;
}

const char* Election::getTitle() const {
    return title;
}

void Election::startElection() {
    isActive = true;
}

void Election::endElection() {
    isActive = false;
}

void Election::addCandidate(Candidate* c) {
    if (candidateCount < 10) {
        candidates[candidateCount++] = c;
    }
}

void Election::displayCandidates() {
    for (int i = 0; i < candidateCount; i++) {
        candidates[i]->getCandidateInfo();
    }
}

Election::~Election() {}

// LocalElection class definitions
LocalElection::LocalElection(const char* t) : Election(t) {}

void LocalElection::calculateResults() {
    std::cout << "Local Election Results:\n";
    displayCandidates();
}

// NationalElection class definitions
NationalElection::NationalElection(const char* t) : Election(t) {}

void NationalElection::calculateResults() {
    std::cout << "National Election Results:\n";
    displayCandidates();
}
