#include <iostream>
#include <iomanip>  // Required for setw, left, fixed, and setprecision
#include <fstream>  // Required for file output (report.txt)
#include <string>   // Required for string type

using namespace std;

// Global Constants
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string CYAN = "\033[36m";
const string YELLOW = "\033[33m";
const string GREEN = "\033[32m";
const string BLUE_CON = "\033[44m\033[33m";
const double d_cost_per_full_pie = 4.00;

// Function Prototypes
void DisplayBanner(bool bColor);
void DisplayMenu(bool bColor);
void SaveFile(string sFileName, int i_pieces, string s_name, double d_budget);
bool validateUserInput(string& value);
bool validateUserInput(int& value);
bool validateUserInput(double& value, int iPieces);
bool getUserInput(int& i_pieces, double& d_budget, string& c_name);

//FUNCTION MAIN()
int main()
{
    // Variables definitions (3 separate types: string, int, double)
    string c_name = "";       // User Name
    int i_pieces = 0;         //Number of Pie Pieces
    double d_budget = 0.00;   //Project Budget
	bool bStartOver = false;  // Flag to determine if the user wants to start over
    bool bColor = true;       // Flag for adding colors to the output
    bool bConsoleBlue = true; // Flag to change Console Color: blue=true/default=false 

    //Displaying Banner_In_Color. Change bColor to False to remove the colors
    DisplayBanner(bColor);

    // Main User Input Loop
    do  // Continuing the initial questioning, until user wants to move forward
    {
        //Resetting the Start Over status
        bStartOver = false;
       
        //USER INPUT SECTION
        //======================================================================= 
        // Calling the input collection and validation Functions
        if (!getUserInput(i_pieces, d_budget, c_name))
        {
            //In case of any problems - will try again
            cout << "\nInvalid information entered. Please try again!" << endl;
            continue;
        }
        //=======================================================================
      
        //Reviewing user's input and determining the next step
        int iOption = 0;
        cout << fixed << setprecision(2);
        cout << "" << endl;
        cout << "" << endl;

        // Styled border and header
        cout << CYAN << "===========================================" << RESET << endl;
        cout << BOLD << YELLOW << "Please, review the information provided:   " << RESET << endl;
        cout << CYAN << "===========================================" << RESET << endl;

        // Styled labels and values (colors applied outside setw to protect alignment)
        cout << CYAN << left << setw(30) << "Baker Name:" << RESET << GREEN << c_name << RESET << endl;
        cout << CYAN << left << setw(30) << "Pie Pieces Requested:" << RESET << GREEN << i_pieces << RESET << endl;
        cout << CYAN << left << setw(30) << "Project Budget:" << RESET << GREEN << "$" << d_budget << RESET << endl;

        cout << CYAN << "-------------------------------------------" << RESET << endl;
        cout << "" << endl;


        bool bNoInputErrors = false;
        while (!bNoInputErrors)  // Input validation with While)
        {
            
            DisplayMenu(bColor);
           
            //User Input and Validation
            cin >> iOption;
            if (cin.fail()) 
            {
                bNoInputErrors = false;
                cout << "\nInvalid input. Please, try again! \n" << endl;
                cin.clear();
                cin.ignore(200, '\n');
            }
            else
            {
                bNoInputErrors = true;
                switch (iOption)
                {
                case 1:
                    // Continue with the calculations
                    break;
                case 2:
                    // Default values for one four-piece pie
                    i_pieces = 4;
                    d_budget = 4.00;
                    break;
                case 3:
                    bStartOver = true;
                    break;
                case 4:
                    // Exit program
                    return 0;
                default:
                    cout << "\nInvalid option. Using Option 1 - Continue with Calculations.";
                    break;
                }
            }
        }

        cout << "" << endl;
    }
    while (bStartOver);  // We will retry the questioneer if user decided to start over the settings.




    // Calculate how many full 4-piece pies can be made with the entered budget

    
    int i_pies_affordable = static_cast<int>(d_budget / d_cost_per_full_pie);
    int i_pieces_affordable = static_cast<int>(d_budget / 1.00);

    // Calculations based on user input (pieces) (scaling from base 4-piece recipe)
    double d_apples = (3.0 / 4.0) * i_pieces;
    double d_eggs = (2.0 / 4.0) * i_pieces;
    double d_sugar = (1.0 / 4.0) * i_pieces;
    double d_flour = (1.0 / 4.0) * i_pieces;
    double d_baking_powder = (1.0 / 4.0) * i_pieces;

    // Estimated Total Cost ($1.00 per piece based on $4.00 for 4 pieces)
    double d_total_cost = 1.00 * i_pieces;
    double d_cost_difference = d_budget - d_total_cost;

    string sInstructions1 = "1. Peel, core, and slice the apples.";
    string sInstructions2 = "2. Mix flour, sugar, and baking powder together in a bowl.";
    string sInstructions3 = "3. Beat the eggs and combine with the dry mixture.";
    string sInstructions4 = "4. Fold in the sliced apples gently into the batter.";

    // Console Output: Summary Table
    //=============================================================================
    //  File Output: Save report and instructions to report.txt 
    //=============================================================================



    cout << "" << endl;
    cout << CYAN << "==================================================================" << RESET << endl;
    cout << BOLD << YELLOW << "                     APPLE PIE PLANNING REPORT                    " << RESET << endl;
    cout << CYAN << "==================================================================" << RESET << endl;

    // Set up precision for floating-point values
    cout << fixed << setprecision(2);

    cout << CYAN << left << setw(50) << "Parameter / Ingredient" << RESET << GREEN << "Amount / Value" << RESET << endl;
    cout << CYAN << "------------------------------------------------------------------" << RESET << endl;
    cout << CYAN << left << setw(50) << "Baker Name:" << RESET << GREEN << c_name << RESET << endl;
    cout << CYAN << left << setw(50) << "Pieces Requested:" << RESET << GREEN << i_pieces << RESET << endl;
    cout << CYAN << "------------------------------------------------------------------" << RESET << endl;
    cout << CYAN << left << setw(50) << "Apples:" << RESET << GREEN << d_apples << RESET << endl;
    cout << CYAN << left << setw(50) << "Eggs:" << RESET << GREEN << d_eggs << RESET << endl;
    cout << CYAN << left << setw(50) << "Sugar (cups):" << RESET << GREEN << d_sugar << RESET << endl;
    cout << CYAN << left << setw(50) << "Flour (cups):" << RESET << GREEN << d_flour << RESET << endl;
    cout << CYAN << left << setw(50) << "Baking Powder (tsp):" << RESET << GREEN << d_baking_powder << RESET << endl;
    cout << CYAN << "------------------------------------------------------------------" << RESET << endl;
    cout << CYAN << left << setw(58) << "Total Estimated Cost:" << RESET << GREEN << "$" << d_total_cost << RESET << endl;
    cout << CYAN << left << setw(58) << "Your Budget:" << RESET << GREEN << "$" << d_budget << RESET << endl;
    cout << CYAN << "------------------------------------------------------------------" << RESET << endl;

    if (d_cost_difference > 0) 
    {
        cout << CYAN << left << setw(50) << "You have money leftover in your budget:" << RESET << GREEN << "$" << d_cost_difference << RESET << endl;
    } 
    else if (d_cost_difference < 0)
    {
        cout << CYAN << left << setw(50) << "You have a deficit in your budget:" << RESET << GREEN << "$" << d_cost_difference << RESET << endl;
        cout << CYAN << left << setw(50) << "You will not be able to complete the project." << RESET << endl;
        cout << CYAN << left << setw(50) << "Consider to increase the budget or decrease the number of pieces." << RESET << endl;
    }
    else
        cout << CYAN << "Well planned! You are within your budget." << endl;

    cout << CYAN << left << setw(50) << "Full Pies Affordable ($4 ea):" << RESET << GREEN << i_pies_affordable << RESET << endl;
    cout << CYAN << left << setw(50) << "Pie pieces Affordable ($1 ea):" << RESET << GREEN << i_pieces_affordable <<RESET << endl;
    cout << YELLOW << "\n==================================================================" << endl;
    cout << "                        BAKING INSTRUCTIONS                       " << endl;
    cout << "==================================================================" << endl;
    //Printing the Instructions from the variables
	for (int i = 0; i < 4; i++) 
    {
        switch (i)
        {
            case 0:
                cout << sInstructions1 << endl;
                break;
            case 1:
                cout << sInstructions2 << endl;
                break;
            case 2:
                cout << sInstructions3 << endl;
                break;
            case 3:
                cout << sInstructions4 << endl;
                break;
        }
	}
    cout << "5. Bake at 350"<< static_cast<char>(248) << "F (175" << static_cast<char>(248) << "C) for 35-40 minutes until golden brown." << endl;
    cout << "==================================================================" << RESET << endl;

    //Saving File
    SaveFile("report.txt", i_pieces, c_name, d_budget);

    return 0;
 }



// DISPLAY BANNER FUNCTION
 void DisplayBanner(bool bColor)
 {
     // The Welcome and the base recipe banner section
     // Define color constants for convenience

     if (bColor == true)
     {
         cout << CYAN << " ------------------------------------------------------------------ " << RESET << endl;
         cout << CYAN << "|" << BOLD << YELLOW << "          APPLE PIE                                               " << RESET << CYAN << "|" << RESET << endl;
         cout << CYAN << " ------------------------------------------------------------------ " << RESET << endl;
         cout << CYAN << "|" << RESET << "Welcome to the Apple Pie planning program!                        " << CYAN << "|" << RESET << endl;
         cout << CYAN << "|" << RESET << "This program will help you to calculate the amount of             " << CYAN << "|" << RESET << endl;
         cout << CYAN << "|" << RESET << "necessary ingredients for your apple pie based on your budget.    " << CYAN << "|" << RESET << endl;
         cout << CYAN << " ------------------------------------------------------------------ " << RESET << endl;
         cout << CYAN << "|" << BOLD << " BASE PIE RECIPE (FOR 4 PIECES):                                  " << CYAN << "|" << RESET << endl;
         cout << CYAN << "|" << RESET << " - 3 apples (" << GREEN << "~$2.25" << RESET << ")                                              " << CYAN << "|" << RESET << endl;
         cout << CYAN << "|" << RESET << " - 2 eggs (" << GREEN << "~$0.60" << RESET << ")                                                " << CYAN << "|" << RESET << endl;
         cout << CYAN << "|" << RESET << " - 1 cup sugar (" << GREEN << "~$0.50" << RESET << ")                                           " << CYAN << "|" << RESET << endl;
         cout << CYAN << "|" << RESET << " - 1 cup flour (" << GREEN << "~$0.35" << RESET << ")                                           " << CYAN << "|" << RESET << endl;
         cout << CYAN << "|" << RESET << " - 1 tsp baking powder (" << GREEN << "~$0.30" << RESET << ")                                   " << CYAN << "|" << RESET << endl;
         cout << CYAN << "|" << RESET << " Total Base Cost:      " << GREEN << "~$4.00" << RESET << "                                     " << CYAN << "|" << RESET << endl;
         cout << CYAN << "|" << RESET << " Cost per one piece:   " << GREEN << "~$1.00" << RESET << "                                     " << CYAN << "|" << RESET << endl;
         cout << CYAN << " ------------------------------------------------------------------ " << RESET << endl;
         cout << "" << endl;
     }
     else
     {
         cout << " ------------------------------------------------------------------ " << endl;
         cout << "|                            APPLE PIE                             |" << endl;
         cout << " ------------------------------------------------------------------ " << endl;
         cout << "|           Welcome to the Apple Pie planning program!             |" << endl;
         cout << "|     This program will help you to calculate the amount of        |" << endl;
         cout << "|  necessary ingredients for your apple pie based on your budget.  |" << endl;
         cout << " ------------------------------------------------------------------ " << endl;
         cout << "|                 BASE PIE RECIPE (FOR 4 PIECES):                  |" << endl;
         cout << "|                     - 3 apples (~$2.25)                          |" << endl;
         cout << "|                     - 2 eggs   (~$0.60)                          |" << endl;
         cout << "|                     - 1 cup sugar (~$0.50)                       |" << endl;
         cout << "|                     - 1 cup flour (~$0.35)                       |" << endl;
         cout << "|                     - 1 tsp baking powder (~$0.30)               |" << endl;
         cout << "|                     Total Base Cost: ~$4.00                      |" << endl;
         cout << "|                  Cost per one piece: ~$1.00                      |" << endl;
         cout << " ------------------------------------------------------------------ " << endl;
         cout << "" << endl;
     }
 }


 // DISPLAY MENU FUNCTION

 void DisplayMenu(bool bColor)
 {
     // The Welcome and the base recipe banner section
     // Define color constants for convenience

     if (bColor == true)
     {
         cout << BLUE_CON;
         cout << "\n Would you like to: " << endl;
         cout << "1. Continue with the calculations" << endl;
         cout << "2. Use default values for one four-piece pie" << endl;
         cout << "3. Start Over" << endl;
         cout << "4. Exit program" << endl;
         cout << RESET;
         cout << "\nPlease, enter your option (1, 2, 3 or 4): ";
      
     }
     else
     {
         cout << "\nWould you like to: " << RESET << endl;
         cout << "1. Continue with the calculations" << endl;
         cout << "2. Use default values for one four-piece pie" << endl;
         cout << "3. Start Over" << endl;
         cout << "4. Exit program" << endl;
         cout << "\nPlease, enter your option (1, 2, 3 or 4): ";
     }
 }


// SAVE FILE FUNCTION
void SaveFile(string sFileName, int i_pieces, string s_name, double d_budget)
{
    double d_total_cost = 1.00 * i_pieces;
    double d_cost_difference = d_budget - d_total_cost;
    double d_apples = (3.0 / 4.0) * i_pieces;
    double d_eggs = (2.0 / 4.0) * i_pieces;
    double d_sugar = (1.0 / 4.0) * i_pieces;
    double d_flour = (1.0 / 4.0) * i_pieces;
    double d_baking_powder = (1.0 / 4.0) * i_pieces;
    int i_pies_affordable = static_cast<int>(d_budget / d_cost_per_full_pie);
    int i_pieces_affordable = static_cast<int>(d_budget / 1.00);
    
    //=============================================================================
    //  File Output: Save report and instructions to report.txt 
    //=============================================================================
    ofstream outfile(sFileName);
    outfile << "==================================================================" << endl;
    outfile << "                     APPLE PIE PLANNING REPORT                    " << endl;
    outfile << "==================================================================" << endl;

    // Set up precision for floating-point values
    outfile << fixed << setprecision(2);

    outfile << left << setw(50) << "Parameter / Ingredient" << "Amount / Value" << endl;
    outfile << "------------------------------------------------------------------" << endl;
    outfile << left << setw(50) << "Baker Name:" << s_name << endl;
    outfile << left << setw(50) << "Pieces Requested:" << i_pieces << endl;
    outfile << "------------------------------------------------------------------" << endl;
    outfile << left << setw(50) << "Apples:" << d_apples << endl;
    outfile << left << setw(50) << "Eggs:" << d_eggs << endl;
    outfile << left << setw(50) << "Sugar (cups):" << d_sugar << endl;
    outfile << left << setw(50) << "Flour (cups):" << d_flour << endl;
    outfile << left << setw(50) << "Baking Powder (tsp):" << d_baking_powder << endl;
    outfile << "------------------------------------------------------------------" << endl;
    outfile << left << setw(58) << "Total Estimated Cost:" << "$" << d_total_cost << endl;
    outfile << left << setw(58) << "Your Budget:" << "$" << d_budget << endl;
    outfile << "------------------------------------------------------------------" << endl;
    if (d_cost_difference > 0)
    {
        outfile << left << setw(50) << "You have money leftover in your budget:" << "$" << d_cost_difference << endl;
    }
    else if (d_cost_difference < 0)
    {
        outfile << left << setw(50) << "You have a deficit in your budget:" << "$" << d_cost_difference << endl;
    }
    else
        outfile << "Well planned! You are within your budget." << endl;

    outfile << left << setw(50) << "Full Pies Affordable ($4 ea):" << i_pies_affordable << endl;
    outfile << left << setw(50) << "Pie pieces Affordable ($1 ea):" << i_pieces_affordable << endl;
    outfile << "\n==================================================================" << endl;
    outfile << "                        BAKING INSTRUCTIONS                       " << endl;
    outfile << "==================================================================" << endl;
    outfile << "1. Peel, core, and slice the apples." << endl;
    outfile << "2. Mix flour, sugar, and baking powder together in a bowl." << endl;
    outfile << "3. Beat the eggs and combine with the dry mixture." << endl;
    outfile << "4. Fold in the sliced apples gently into the batter." << endl;
    outfile << "5. Bake at 350°F (175°C) for 35-40 minutes until golden brown." << endl;
    outfile << "==================================================================" << endl;
    outfile.close();

    cout << "\nYour report and baking instructions have been successfully saved to 'report.txt'." << endl;
}


//GET USER INPUT FUNCTION
//Function to Initiate User Input and Validation
bool getUserInput(int& i_pieces, double& d_budget, string& c_name)
{
    // If all three inpus are validated positively, the function will return True
    bool bUserNameOk = validateUserInput(c_name); // Name input validation
    bool bUserPiecesNumberOk = validateUserInput(i_pieces); // Number of pieces input validation
    bool bUserBudgetOk = validateUserInput(d_budget, i_pieces); // Budget input validation based on number of pieces

    // If all three requirements are met, returning true.
    return (bUserNameOk && bUserPiecesNumberOk && bUserBudgetOk) ? true : false;
}

//Function to validate User Name Input
bool validateUserInput(string& value)
{
    // This function will return True if User Input is correct, otherwise it will prompt the user to re-enter the value. 
    const int MIN_NAME_LENGTH = 2;  // Minimum length for the name input
    const int MAX_NAME_LENGTH = 60; // Maximum length for the name input    

    //Starting the User Name input validation. (String Value)
    std::cout << "Hello!" << endl;
    do //This is an infinite loop that will continue until the user provides valid input.
    {
        std::cout << "Please, enter your name (single word string, e.g., Mike): ";
        std::cin >> value;
        //Validation
        if (std::cin.fail()) // Input is wrong
        {
            std::cout << "Invalid input. Please try again: ";
            std::cin.clear();
            std::cin.ignore(200, '\n');
            continue;
        }
        else  // Input is correct, let's check the string length
        {
            if (value.empty() || value.length() < MIN_NAME_LENGTH || value.length() > MAX_NAME_LENGTH)
            {
                std::cout << "\nIncorrect input. Please try again. ";
                continue; // Prompt the user again for input
            }
            else // Name entered correctly. Moving forward to the next step.
            {
                std::cout << "\nHi, " << value << "! Nice to meet you!" << endl;
                return true;
            }
        }
    } while (true); // Loop until valid input is received
}

//Function to validate the User Input for Number of pieces
bool validateUserInput(int& value)
{
    // This function will return True if User Input is correct, otherwise it will prompt the user to re-enter the value. 
    const int MAX_NUM_PIECES = 70; // Maximum number of pie pieces    

    std::cout << "\nWelcome to the Apple Pie planning program!" << endl;

    //Starting the User Name input validation. (Integer Value)
    while (true) //This is an infinite loop that will continue until the user provides valid input.
    {
        // Number of pie pieces
        std::cout << "\nPlease, enter the number of pie pieces you want to bake (e.g., 4): ";
        std::cin >> value; 

        //Evaluating the User Input
        if (std::cin.fail()) // Input is wrong
        {
            std::cout << "\nInvalid input detected. Please enter a valid number.";
            std::cin.clear();
            std::cin.ignore(200, '\n');
            continue;
        }
        else //Input is correct, let's check the numbers
        {
            if ((value >= 8) && (value <= 20)) // Between 8 and 20 pieces 
            {
                std::cout << "\nYour Project will require quite some time to complete!" << endl;
                return true;
            }
            else if (value > MAX_NUM_PIECES) //Over the limit
            {
                std::cout << "\nYour Project needs a baking factory with staff to complete! You should start your own business! Please try again!" << endl;
                continue;
            }
            else if (value <= 0) //Too litle
            {
                std::cout << "\n Your number is too low... Try again!" << endl;
                continue;
            }
            else // All good
                return true;
        }
    } // Loop until valid input is received
}

//Function to validate the User Input for Budget
bool validateUserInput(double& value, int iPieces)
{

    //Starting the User Name input validation. (Integer Value)
    do //This is an infinite loop that will continue until the user provides valid input.
    {
        //BUDGET
        std::cout << "\nWhat is your budget for the project? (e.g., $10.00): $";
        std::cin >> value;
        if (cin.fail())
        {
            cout << "\nInvalid input. Please, try again!";
            cin.clear();
            cin.ignore(200, '\n');
            continue;
        }
        else
        {
            // We know that one piece will cost $1.00 to bake.
            // Based on user input, we will calculate if the budget is sufficient to complete the project.
            if (static_cast<int>(value) < 1.00 * iPieces)
            {
                cout << "\nYour budget for the project is too small. <--" << endl;
                cout << "Please, consider to increase the budget and enter a new amount...";
                continue;
            }
            else
            {
                cout << "\nYour budget for the project is sufficient." << endl;
                return true;
            }
        }
    } while (true);
}

