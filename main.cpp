 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person 
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    void run(int howFast, bool startWithLeftFoot);

    struct Foot
    {
        int stepSize() 
        {
            return 7;
        }
    
        void stepForward(int howFast)
        {
            std::cout << "Stepped forward" << stepSize()*howFast << "." << std::endl;
        }
    };

    Foot leftFoot, rightFoot;

};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot)
    {
        leftFoot.stepForward(howFast);
        rightFoot.stepForward(howFast);
    }
    else
    {
        rightFoot.stepForward(howFast);
        leftFoot.stepForward(howFast);
    }
    
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();

}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

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

    void hostTournament(int numParticipants, int tournamentDate, float purse, float firstPlacePercentage, float secondPlacePercentage, float thirdPlacePercentage); 
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
    std::cout  <<  "good to go!"  <<  std::endl;
}
