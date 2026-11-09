#include <iostream>
#include <iomanip>  // Required for setw, left, fixed, and setprecision
#include <fstream>  // Required for file output (report.txt)
#include <string>   // Required for string type

using namespace std;

int main()
{
    // Variables definitions (3 separate types: string, int, double)
    string c_name = "";
    int i_pieces = 0;
    double d_budget = 0.00;

	const int MIN_NAME_LENGTH = 2; // Minimum length for the name input
    const int MAX_NAME_LENGTH = 60; // Maximum length for the name input

    const int MAX_NUM_PIECES = 70; // Maximum number of pie pieces


    // The Welcome and the base recipe banner section
    cout << " ------------------------------------------------------------------ " << endl;
    cout << "|          APPLE PIE                                               |" << endl;
    cout << " ------------------------------------------------------------------ " << endl;
    cout << "|Welcome to the Apple Pie planning program!                        |" << endl;
    cout << "|This program will help you to calculate the amount of             |" << endl;
    cout << "|necessary ingredients for your apple pie based on your budget.    |" << endl;
    cout << " ------------------------------------------------------------------ " << endl;
    cout << "| BASE PIE RECIPE (FOR 4 PIECES):                                  |" << endl;
    cout << "| - 3 apples (~$2.25)                                              |" << endl;
    cout << "| - 2 eggs (~$0.60)                                                |" << endl;
    cout << "| - 1 cup sugar (~$0.50)                                           |" << endl;
    cout << "| - 1 cup flour (~$0.35)                                           |" << endl;
    cout << "| - 1 tsp baking powder (~$0.30)                                   |" << endl;
    cout << "| Total Base Cost:      ~$4.00                                     |" << endl;
    cout << "| Cost per one piece:   ~$1.00                                     |" << endl;
    cout << " ------------------------------------------------------------------ " << endl;
    cout << "" << endl;

    //User Input Section
    //Name
    cout << "--> Hello!" << endl;
    cout << "--> Please, enter your name (single word string, e.g., John): ";
	cin >> c_name;

    if (c_name.empty() || c_name.length() < MIN_NAME_LENGTH || c_name.length() > MAX_NAME_LENGTH)
        {
            cout << "\n(!) Please, enter a valid name: ";
            cin >> c_name;
        }

    // Number of pie pieces
	cout << "\nHi, " << c_name << "! Welcome to the Apple Pie planning program! <--" << endl;
    cout << "\n--> Please, enter the number of pie pieces you want to bake (e.g., 4): ";
    cin >> i_pieces;
    if (cin.fail())
    {
        cout << "\nInvalid input detected. Default value of 4 pieceww will be used.";
        cin.clear();
        cin.ignore(200, '\n');
        i_pieces = 4;
    }
    else
    {
        if (!(i_pieces <= 8) && (i_pieces > 20 && i_pieces <= MAX_NUM_PIECES)) // Not less than 8 or greater than 20 and less than or equal to 70
        {
            cout << "\nYour Project will require quite some time to complete! <--" << endl;
        }
        else if (i_pieces > 71)
        {
            cout << "\nYour Project needs a baking factory with staff to complete! You should start your own business! <--" << endl;
        }
        else if (i_pieces <= 0)
        {
            cout << "\n(!) You entered 0 pieces! Good bye!" << endl;
            return (0);
        }
    }
    
    //BUDGET
    cout << "\n--> What is your budget for the project (e.g., $10.00): $";
    cin >> d_budget;
    if (cin.fail())
    {
        cout << "\nInvalid input. Default value of $20.00 will be used. <--";
        cin.clear();
        cin.ignore(200, '\n');
        d_budget = 20.00;
    }
    else
    {
        // We know that one piece will cost $1.00 to bake.
        // Based on user input, we will calculate if the budget is sufficient to complete the project.
        if (static_cast<int>(d_budget) < 1.00 * i_pieces)
        {
            cout << "\nYour budget for the project is too small. <--" << endl;
            cout << "Please, consider to increase the budget and enter a new amount: $";
            cin >> d_budget;
        }
        else
        {
            cout << "\nYour budget for the project is sufficient." << endl;
        }
    }
    //Reviewing user's input and determining the next step
    int i_option = 0;
    cout << fixed << setprecision(2);
    cout << "" << endl;
    cout << "" << endl;
    cout << "===========================================" << endl;
    cout << "Please, review the information provided:   " << endl;
    cout << "===========================================" << endl;
    cout << left << setw(30) << "Baker Name:" << c_name << endl;
    cout << left << setw(30) << "Pie Pieces Requested:" << i_pieces << endl;
    cout << left << setw(30) << "Project Budget:" << "$" << d_budget<< endl;
    cout << "-------------------------------------------" << endl;
    cout << "" << endl;
    cout << "\nWould you like to: " << endl;
    cout << "   1. Continue with the calculations" << endl;
    cout << "   2. Use default values for one four-piece pie" << endl;
    cout << "   3. Exit program" << endl;
    cout << "\nPlease, enter your option (1, 2, or 3): ";
    cin >> i_option;
    if (cin.fail())
    {
        cout << "\nInvalid input. Option 1 will be used instead";
        cin.clear();
        cin.ignore(200, '\n');
    }
    else
    {
        switch (i_option)
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
            // Exit program
            return 0;
        default:
            cout << "\nInvalid option. Using Option 1 - Continue with Calculations.";
            break;
        }
    }
    cout << "" << endl;

    // Calculate how many full 4-piece pies can be made with the entered budget

    double d_cost_per_full_pie = 4.00;
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

    // Console Output: Summary Table
    //=============================================================================
    //  File Output: Save report and instructions to report.txt 
    //=============================================================================
    cout << "" << endl;
    cout << "==================================================================" << endl;
    cout << "                     APPLE PIE PLANNING REPORT                    " << endl;
    cout << "==================================================================" << endl;
       
    // Set up precision for floating-point values
    cout << fixed << setprecision(2); 

    cout << left << setw(50) << "Parameter / Ingredient" << "Amount / Value" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << left << setw(50) << "Baker Name:" << c_name << endl;
    cout << left << setw(50) << "Pieces Requested:" << i_pieces << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << left << setw(50) << "Apples:" << d_apples << endl;
    cout << left << setw(50) << "Eggs:" << d_eggs << endl;
    cout << left << setw(50) << "Sugar (cups):" << d_sugar << endl;
    cout << left << setw(50) << "Flour (cups):" << d_flour << endl;
    cout << left << setw(50) << "Baking Powder (tsp):" << d_baking_powder << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << left << setw(58) << "Total Estimated Cost:" << "$" << d_total_cost << endl;
    cout << left << setw(58) << "Your Budget:" << "$" << d_budget << endl;
    cout << "------------------------------------------------------------------" << endl;
    if (d_cost_difference > 0) 
    {
        cout << left << setw(50) << "You have money leftover in your budget:" << "$" << d_cost_difference << endl;
    } 
    else if (d_cost_difference < 0)
    {
        cout << left << setw(50) << "You have a deficit in your budget:" << "$" << d_cost_difference << endl;
        cout << left << setw(50) << "You will not be able to complete the project." << endl;
        cout << left << setw(50) << "Consider to increase the budget or decrease the number of pieces." << endl;
    }
    else
        cout << "Well planned! You are within your budget." << endl;

    cout << left << setw(50) << "Full Pies Affordable ($4 ea):" << i_pies_affordable << endl;
    cout << left << setw(50) << "Pie pieces Affordable ($1 ea):" << i_pieces_affordable << endl;
    cout << "\n==================================================================" << endl;
    cout << "                        BAKING INSTRUCTIONS                       " << endl;
    cout << "==================================================================" << endl;
    cout << "1. Peel, core, and slice the apples." << endl;
    cout << "2. Mix flour, sugar, and baking powder together in a bowl." << endl;
    cout << "3. Beat the eggs and combine with the dry mixture." << endl;
    cout << "4. Fold in the sliced apples gently into the batter." << endl;
    cout << "5. Bake at 350°F (175°C) for 35-40 minutes until golden brown." << endl;
    cout << "==================================================================" << endl;

    //=============================================================================
    //  File Output: Save report and instructions to report.txt 
    //=============================================================================
    ofstream outfile("report.txt");
    outfile << "==================================================================" << endl;
    outfile << "                     APPLE PIE PLANNING REPORT                    " << endl;
    outfile << "==================================================================" << endl;

    // Set up precision for floating-point values
    outfile << fixed << setprecision(2);

    outfile << left << setw(50) << "Parameter / Ingredient" << "Amount / Value" << endl;
    outfile << "------------------------------------------------------------------" << endl;
    outfile << left << setw(50) << "Baker Name:" << c_name << endl;
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

    return 0;
}