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


// Thing 1) exercise bike 
struct ExerciseBike
{
// 5 properties:
//     1) number of seat adjustments (int)
    int numSeatAdjustments = 12;
//     2) maximum resistance (float)
    float maximumResistance = 15.0f;
//     3) number of program modes (int)
    int numProgramModes = 8;
//     4) number of pulse readers (int)
    int numPulseReaders = 2;
//     5) power consumed (float)
    int powerConsumed = 12.0f;
// 3 things it can do:
//     1) begin a workout program
    void beginWorkoutProgram(int selectedProgram);
//     2) read pulse
    float readPulse(); // returns pulse in beats per minute
//     3) calculate caloric burn
    float calculateCaloricBurn(float weight); // returns total calories burned during session
};

// Thing 2) department store
struct DepartmentStore
{
// 5 properties:
//     1) number of employees (int)
    int numEmployees = 70;
//     2) number of departments (int)
    int numDepartments = 16;
//     3) amount of electricity used per month (float)
    float electricityPerWeek = 1200.0f;
//     4) amount of profit per week (int)
    int profitPerWeek = 60000;
//     5) name (std::string)
    std::string name = "David's";
// 3 things it can do:
//     1) open/close 
    bool open(); // returns true to denote open store

    bool close(); // returns false to denote closed store
//     2) host a sale
    void hostSale(float discountRate);
//     3) sell an item to a customer
    float sellItem(); // returns the total sale price
};

// Thing 3) golf course

struct GolfCourse
{
    struct Golfer
    {
//     5 properties:
//     1) Name (std::string)
        std::string name = " ";
//     2) Handicap (int)
        int handicap = 0;
//     3) Years of Experience (int)
        int yearsOfExperience = 0;
//     4) Tournament winner? (bool)
        bool tournamentWinner = false;
//     5) Tournaments won (int)
        int tournamentsWon = 0;
//     3 things it can do:
//     1) drive
        float drive(float power, float accuracy); // returns distance to tee
//     2) putt
        float putt(float power, float accuracy); // returns distance to tee
//     3) chip
        float chip(float power, float accuracy); // returns distance to tee
    };
// 5 properties:
//     1) number of holes (int)
    int numHoles = 18;
//     2) number of golfers per week (double)
    double golfersPerWeek = 15000;
//     3) length, in yards (float)
    float courseLength = 6500;
//     4) number of golfers per party (int)
    int golfersPerParty = 4;
//     5) members-only (or not) (bool)
    bool membersOnly = false;
// 3 things it can do:
//     1) host a tournament
    void hostTournament(int numParticipants, int tournamentDate, float purse, float firstPlacePercentage,         float secondPlacePercentage, float thirdPlacePercentage); 
//     2) suspend play for weather reasons
    bool suspendPlay(float duration); // returns false to suspend play for the specific duration; would then return back to true, resuming play 
//     3) change hole location on green
    void changeHoleLocation(int holeNum, float latitude, float longitude, Golfer tester); 

    Golfer golfPro;
};

// Thing 4) library
struct Library
{
    struct LibraryCard
    {
//    5 properties:
//     1) ID number (int)
        int iDNumber = 000000000;
//     2) Name (std::string)
        std::string name = " ";
//     3) Number of books checked out (int)
        int booksCheckedOut = 0;
//     4) Fees due (float)
        float feesDue = 0.0f;
//     5) Registration date (double)
        double registrationDate = 00000000;
// 3 things it can do:
//     1) return a list of books checked out
        std::string allBooksCheckedOut(); // returns a printout of titles of all books             checked out by that card
//     2) calculate total fees owed over the past year
        float calculateYearlyFeesOwed(int year); // returns total fees owed for given              year
//     3) grant access to computer terminal
        void grantComputerAccess(float duration = 1.0f);
    };
// 5 properties:
//     1) number of books (double)
    double numBooks = 35000;
//     2) number of library cards/users (double)
    double totalLibraryCards = 10000;
//     3) number of employees/volunteers (int)
    int numEmployees = 20;
//     4) book/media checkout periods, in days (int)
    int checkoutPeriod = 14;
//     5) late fees, amounts, etc. per day (float)
    float lateFee = .35f; 
// 3 things it can do:
//     1) host a book sale
    void hostBookSale(double date, int numBooks, std::string saleName);
//     2) check a book out to a library card
    bool checkOutBook(LibraryCard libraryCard); // returns true to denote book as checked out
//     3) suspend privileges to user with delinquent checkouts/fees
    bool suspendCheckoutPrivileges(LibraryCard libraryCard); // returns false to suspend user privileges until determined threshold is met

    LibraryCard memberOfTheMonth;  
};

// Thing 5) Drumhead
struct Drumhead
{
// 5 properties:
//     1) diameter, in inches (int)
    int diameter = 14;
//     2) ply thickness, in mm (float)
    float plyThickness = 10.0f;
//     3) number of plies (int)
    int plies = 1;
//     4) brand (std::string)
    std::string brand = "Remo";
//     5) material (std::string)
    std::string material = "film";
// 3 things it can do:
//     1) wrinkle
    void wrinkle();
//     2) break
    bool breakDrumhead(); // returns true to alert SnareDrum struct that something is broken
//     3) tighten/loosen
    void tighten(float tension);
    void loosen(float tension);
};

// Thing 6) Snare Wires
struct SnareWires
{
// 5 properties:
//     1) number of wires (int)
    int numWires = 20;
//     2) material (std::string)
    std::string material = "steel";
//     3) wire gauge, in mm (float)
    float wireGauge = .6f;
//     4) brand (std::string)
    std::string brand = "Puresound";
//     5) with straps/without straps (bool)
    bool withStraps = false;
// 3 things it can do:
//     1) crack
    void crack();
//     2) buzz
    void buzz();
//     3) break a wire
    bool breakSnareWires(); // returns true to alert SnareDrum struct that something is broken
};

// Thing 7) Snare Strainer
struct SnareStrainer
{
// 5 properties:
//     1) mounting distance, in inches (float)
    float mountingDistance = 2.0f;
//     2) number of mounting screws (int)
    int numMountingScrews = 2;
//     3) maximum tension, in poundsforce (float)
    float maximumTension = 12.5f;
//     4) brand (std::string)
    std::string brand = "Ludwig";
//     5) type (std::string)
    std::string strainerType = "side-action";
// 3 things it can do:
//     1) engage snares
    bool engageSnares(); // returns true to snareWires
//     2) disengage snares
    bool disengageSnares(); // returns false to snareWires
//     3) tighten snares
    float tightenSnares(SnareWires* snareWires, float tension); // tightens or loosens snareWires by given tension
};

// Thing 8) Drum Shell
struct DrumShell
{
// 5 properties:
//     1) brand (std::string)
    std::string brand = "Pearl";
//     2) material (std::string)
    std::string material = "birch";
//     3) diameter, in inches (int)
    int diameter = 14;
//     4) bearing edge angle (float)
    float bearingEdgeAngle = 45.0f;
//     5) depth, in inches (float)
    float depth = 5.5f;
// 3 things it can do:
//     1) crack
    bool crackShell(); // returns true to alert SnareDrum struct that something is broken
//     2) be vented
    void beVented(int numHoles, float holeDiameter);
//     3) resonate
    void resonate(float velocity);
};

// Thing 9) Lugs
struct Lug
{
// 5 properties:
//     1) brand (std::string)
    std::string brand = "Pearl";
//     2) length (float)
    float length = 2.0f;
//     3) single-sided? (bool)
    bool singleSided = false;
//     4) decoupled? (bool)
    bool decoupled = true;
//     5) material (std::string)
    std::string material = "steel";
// 3 things it can do:
//     1) tighten drum head
    void tightenDrumhead(float tension);
//     2) loosen drum head
    void loosenDrumhead(float tension);
//     3) overtighten
    bool overtighten(); // returns true to alert SnareDrum struct that something is broken
};

// Thing 10) Snare Drum
struct SnareDrum
{
// 5 properties:
//     1) Drumhead
    Drumhead drumhead;
//     2) Snare Wires
    SnareWires snareWires;
//     3) Snare Strainer
    SnareStrainer snareStrainer;
//     4) Drumshell
    DrumShell drumshell;
//     5) Lugs
    Lug lug1, lug2, lug3, lug4, lug5, lug6, lug7, lug8;
// 3 things it can do:
//     1) drive backbeat
    void driveBackbeat(float bpm);
//     2) define drum sound
    void defineDrumSound();
//     3) break
    bool breakDrum(); // returns true until fixed
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
