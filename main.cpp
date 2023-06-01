/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct ExerciseBike
{
    int numSeatAdjustments = 12;
    float maximumResistance = 15.0f;
    int numProgramModes = 8;
    int numPulseReaders = 2;
    int powerConsumed = 12.0f;

    void beginWorkoutProgram(int selectedProgram);
    float readPulse();
    float calculateCaloricBurn(float weight, float timeSpent);
};

void ExerciseBike::beginWorkoutProgram(int selectedProgram)
{
    std::cout << "Beginning Workout #" << selectedProgram << std::endl;
}

float ExerciseBike::readPulse()
{
    float pulseRead = 30.0f;
    return pulseRead * 3.0f;
}

float ExerciseBike::calculateCaloricBurn(float weight, float timeSpent)
{
    std::cout << "Calculating caloric burn..." << std::endl;
    return weight * readPulse() * timeSpent;
}

struct DepartmentStore
{
    int numEmployees = 70;
    int numDepartments = 16;
    float electricityPerWeek = 1200.0f;
    int profitPerWeek = 60000;
    std::string name = "David's";

    bool open();
    bool close();
    void hostSale(float discountRate);
    float sellItem(std::string itemName, float price, float taxRate, bool isOnSale, float discountRate);
};

bool DepartmentStore::open()
{
    std::cout << "Store Open!" << std::endl;
    return 1;
}

bool DepartmentStore::close()
{
    std::cout << "Store Closed." << std::endl;
    return 0;
}

void DepartmentStore::hostSale(float discountRate)
{
    std::cout << "We're having a sale! Enjoy " << discountRate << "% off!" << std::endl;
}

float DepartmentStore::sellItem(std::string itemName, float price, float taxRate, bool isOnSale, float discountRate)
{
    float totalPrice = price;
    if(isOnSale) 
        totalPrice -= (totalPrice * discountRate);
    totalPrice += (totalPrice * taxRate);
    
    std::cout << "Sold!" << itemName << " has sold for " << totalPrice << std::endl;
    
    return totalPrice;
}

struct GolfCourse
{
    int numHoles = 18;
    double golfersPerWeek = 15000;
    float courseLength = 6500;
    int golfersPerParty = 4;
    bool membersOnly = false;

    struct Golfer
    {
        std::string name = " ";
        int handicap = 0;
        int yearsOfExperience = 0;
        bool tournamentWinner = false;
        int tournamentsWon = 0;

        float drive(float power, float accuracy, float distanceToTee);
        float putt(float power, float accuracy, float distanceToTee);
        float chip(float power, float accuracy, float distanceToTee);
    };

    void hostTournament(int numParticipants, int tournamentDate, float purse, float firstPlacePercentage,         float secondPlacePercentage, float thirdPlacePercentage); 
    bool suspendPlay(float duration);
    void changeHoleLocation(int holeNum, float latitude, float longitude, Golfer tester); 

    Golfer golfPro;
};

float GolfCourse::Golfer::drive(float power, float accuracy, float distanceToTee)
{
    return distanceToTee - (power * distanceToTee * .75f * accuracy);
}

float GolfCourse::Golfer::putt(float power, float accuracy, float distanceToTee)
{
    return distanceToTee - (power * distanceToTee * .25f * accuracy);
}

float GolfCourse::Golfer::chip(float power, float accuracy, float distanceToTee)
{
    return distanceToTee - (power * distanceToTee * .50f * accuracy);
}

void GolfCourse::hostTournament(int numParticipants, int tournamentDate, float purse, float firstPlacePercentage, float secondPlacePercentage, float thirdPlacePercentage)
{
    std::cout << "It's a golf tournament!" << std::endl;
    std::cout << numParticipants << " will gather on " << tournamentDate << "to compete for " << purse << " in winnings!" << std::endl;
    std::cout << "1st prize will win: " << purse * firstPlacePercentage << std::endl;
    std::cout << "2nd prize will win: " << purse * secondPlacePercentage << std::endl;
    std::cout << "3rd prize will win: " << purse * thirdPlacePercentage << std::endl;
}

bool GolfCourse::suspendPlay(float duration)
{
    if(duration == 0.0f) 
    {
        std::cout << "No suspension necessary!";
        return 1;
    }
    std::cout << "Play will be suspended for " << duration << std::endl;
    return 0;
}

void GolfCourse::changeHoleLocation(int holeNum, float latitude, float longitude, Golfer tester)
{
    std::cout << "Hole at #" << holeNum << " has been moved to " << latitude << "x" << longitude << ". " << tester.name << " has verified fair placement." << std::endl;
}

struct Library
{
    double numBooks = 35000;
    double totalLibraryCards = 10000;
    int numEmployees = 20;
    int checkoutPeriod = 14;
    float lateFee = .35f; 

    struct LibraryCard
    {
        int iDNumber = 000000000;
        std::string name = " ";
        int booksCheckedOut = 0;
        float feesDue = 0.0f;
        double registrationDate = 00000000;

        std::string allBooksCheckedOut();
        float calculateYearlyFeesOwed(int year);
        void grantComputerAccess(float duration = 1.0f);
    };

    void hostBookSale(double date, int numBooksForSale, std::string saleName);
    bool checkOutBook(LibraryCard libraryCard);
    bool suspendCheckoutPrivileges(LibraryCard libraryCard); 

    LibraryCard memberOfTheMonth;  
};

std::string Library::LibraryCard::allBooksCheckedOut()
{
    std::string result = "These are all the books checked out by ";
    result += std::to_string(iDNumber);
    return result;
}

float Library::LibraryCard::calculateYearlyFeesOwed(int year)
{
    std::cout << iDNumber << "owed " << feesDue << " in " << year << "." << std::endl;
    return feesDue;
}

void Library::LibraryCard::grantComputerAccess(float duration)
{
    std::cout << "Success! Computer access granted for " << duration << "hours. Enjoy!" << std::endl;
}

void Library::hostBookSale(double date, int numBooksForSale, std::string saleName)
{
    std::cout << "It's a book sale! " << saleName << " will be held on " << date << ". Choose from " << numBooksForSale << "books and support your local library!" << std::endl;
}

bool Library::checkOutBook(LibraryCard libraryCard)
{
    if(libraryCard.feesDue > 1000000.0f)
    {
        std::cout << "Error: " << libraryCard.iDNumber << "owes more than one million dollars in late fees!";
        return 0;
    }
    std::cout << "Book checked out to" << libraryCard.iDNumber;
    return 1;
}

bool Library::suspendCheckoutPrivileges(LibraryCard libraryCard)
{
    if (libraryCard.feesDue > 1000000.0f)
    {
        std::cout << "Fees due total over one million dollars. Checkout privileges suspended." << std::endl;
        return 0;
    }
        std::cout << "Fees insufficient for suspension. :(" << std::endl;
        return 1;
}


struct Drumhead
{
    int diameter = 14;
    float plyThickness = 10.0f;
    int plies = 1;
    std::string brand = "Remo";
    std::string material = "film";

    void wrinkle();
    bool breakDrumhead();
    void tighten(float tension);
    void loosen(float tension);
};

void Drumhead::wrinkle()
{
    std::cout << "Drumhead has wrinkled..." << std::endl;
}

bool Drumhead::breakDrumhead()
{
    std::cout << "Drumhead has broken!" << std::endl;
    return 1;
}

void Drumhead::tighten(float tension)
{
    std::cout << "Drumhead has been tightened by " << tension << "." << std::endl;
}

void Drumhead::loosen(float tension)
{
    std::cout << "Drumhead has been loosened by " << tension << "." << std::endl;
}

struct SnareWires
{
    int numWires = 20;
    std::string material = "steel";
    float wireGauge = .6f;
    std::string brand = "Puresound";
    bool withStraps = false;

    void crack();
    void buzz();
    bool breakSnareWires();
};

void SnareWires::crack()
{
    std::cout << "Crack!" << std::endl;
}

void SnareWires::buzz()
{
    std::cout << "Bzzzzzzz..." << std::endl;
}

bool SnareWires::breakSnareWires()
{
    std::cout << "Snare wires have broken!" << std::endl;
    return 1;
}

struct SnareStrainer
{
    float mountingDistance = 2.0f;
    int numMountingScrews = 2;
    float maximumTension = 12.5f;
    std::string brand = "Ludwig";
    std::string strainerType = "side-action";

    bool engageSnares();
    bool disengageSnares();
    float tightenSnares(SnareWires* snareWires, float tension);
};

bool SnareStrainer::engageSnares()
{
    std::cout << "Snares engaged!" << std::endl;
    return 1;
}

bool SnareStrainer::disengageSnares()
{
    std::cout << "Snares disengaged." << std::endl;
    return 0;
}

float SnareStrainer::tightenSnares(SnareWires *snareWires, float tension)
{
    std::cout << snareWires << "have been tightened by " << tension << "." << std::endl;
    return tension;
}


struct DrumShell
{
    std::string brand = "Pearl";
    std::string material = "birch";
    int diameter = 14;
    float bearingEdgeAngle = 45.0f;
    float depth = 5.5f;

    bool crackShell();
    void beVented(int numHoles, float holeDiameter);
    void resonate(float velocity);
};

bool DrumShell::crackShell()
{
    std::cout << "Drum shell has cracked!" << std::endl;
    return 1;
}

void DrumShell::beVented(int numHoles, float holeDiameter)
{
    std::cout << "Drum shell has been vented with " << numHoles << "holes of " << holeDiameter << " in. in diameter." << std::endl;
}

void DrumShell::resonate(float velocity)
{
    if(velocity < 35.0f) 
        std::cout << "no resonance..." << std::endl;
    else 
        std::cout << "resonance with " << velocity << " velocity!" << std::endl;
}

struct Lug
{
    std::string brand = "Pearl";
    float length = 2.0f;
    bool singleSided = false;
    bool decoupled = true;
    std::string material = "steel";

    void tightenDrumhead(float tension);
    void loosenDrumhead(float tension);
    bool overtighten();
};

void Lug::tightenDrumhead(float tension)
{
    std::cout << "Drumhead tightened by " << tension << "." << std::endl;
}

void Lug::loosenDrumhead(float tension)
{
    std::cout << "Drumhead loosened by " << tension << "." << std::endl;
}

bool Lug::overtighten()
{
    std::cout << "Lug has overtightened!" << std::endl;
    return 1;
}

struct SnareDrum
{
    Drumhead drumhead;
    SnareWires snareWires;
    SnareStrainer snareStrainer;
    DrumShell drumshell;
    Lug lug1, lug2, lug3, lug4, lug5, lug6, lug7, lug8;

    void driveBackbeat(float bpm);
    void defineDrumSound();
    bool breakDrum();
};

void SnareDrum::driveBackbeat(float bpm)
{
    std::cout << "Ready? 1, 2, 3, 4..." << std::endl;
    std::cout << "That's a groovy " << bpm << " bpm backbeat!" << std::endl;
}

void SnareDrum::defineDrumSound()
{
    std::cout << "Wow, what a unique drum sound!" << std::endl;
}

bool SnareDrum::breakDrum()
{
    std::cout << "Snare drum broken!" << std::endl;
    return 1;
}

int main()
{
    Example::main();
    
    
    std::cout  <<  "good to go!"  <<  std::endl;
}
