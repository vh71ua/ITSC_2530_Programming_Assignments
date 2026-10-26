#include <windows.h>
#include <iostream>
#include <iomanip>  // Required for setw, left, fixed, and setprecision
#include <fstream>  // Required for file output (report.txt)

using namespace std;

int main()
{
    // Variables definitions (3 separate types: char array, int, double)
    char c_name[50] = "Guest";
    int i_pieces = 4;
    double d_budget = 4.00;

    // Setting the console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Interacting with the User - ASCII Art Banner
    cout << "" << endl;
    cout << "░█████╗░██████╗░██████╗░██╗░░░░░███████╗░░░░░██████╗░██╗███████╗" << endl;
    cout << "██╔══██╗██╔══██╗██╔══██╗██║░░░░░██╔════╝░░░░░██╔══██╗██║██╔════╝" << endl;
    cout << "███████║██████╔╝██████╔╝██║░░░░░█████╗░░░░░░░██████╔╝██║█████╗░░" << endl;
    cout << "██╔══██║██╔═══╝░██╔═══╝░██║░░░░░██╔══╝░░░░░░░██╔═══╝░██║██╔══╝░░" << endl;
    cout << "██║░░██║██║░░░░░██║░░░░░███████╗███████╗░░░░░██║░░░░░██║███████╗" << endl;
    cout << "╚═╝░░╚═╝╚═╝░░░░░╚═╝░░░░░╚══════╝╚══════╝░░░░░╚═╝░░╚═╝╚═╝╚══════╝" << endl;
    cout << "" << endl;

    // Welcome and Base Recipe Banner Section
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
    cout << "| Total Base Cost: ~$4.00                                          |" << endl;
    cout << " ------------------------------------------------------------------ " << endl;
    cout << "" << endl;

    // User Input Section
    cout << "Hello!" << endl;
    cout << "Please, enter:" << endl;
    cout << "- Your name (single word string, e.g., John)" << endl;
    cout << "- Number of pieces of pie you want to make (whole integer, e.g., 4)" << endl;
    cout << "- Your budget for the cake in $ (e.g., 20.00)" << endl;
    cout << "Your input should be in one line with answers separated by spaces (example: John 4 20.00): " << endl;
    cin >> c_name >> i_pieces >> d_budget;

    // Input Error Handling using a Selection Statement (if) -- allowed once in the instructions
    if (cin.fail()) {
        cout << "\nInvalid input format detected!" << endl;
        cout << "Applying standard fallback recipe values (4 pieces, $4.00 budget).\n" << endl;

        // Clear error flags
        cin.clear();
        // Discard bad input from the stream buffer
        cin.ignore(500, '\n');

        // Reset defaults so calculations remain valid
        i_pieces = 4;
        d_budget = 4.00;
    }
    else {
        // Clear out any trailing junk if input succeeded
        cin.clear();
        cin.ignore(500, '\n');
    }

    // Calculations based on user input (pieces) (scaling from base 4-piece recipe)
    double d_apples = (3.0 / 4.0) * i_pieces;
    double d_eggs = (2.0 / 4.0) * i_pieces;
    double d_sugar = (1.0 / 4.0) * i_pieces;
    double d_flour = (1.0 / 4.0) * i_pieces;
    double d_baking_powder = (1.0 / 4.0) * i_pieces;

    // Estimated Total Cost ($1.00 per piece based on $4.00 for 4 pieces)
    double d_total_cost = 1.00 * i_pieces;
    double d_cost_difference = d_budget - d_total_cost;

    // Calculate how many full 4-piece pies can be made with the entered budget
    double d_cost_per_full_pie = 4.00;
    int i_pies_affordable = static_cast<int>(d_budget / d_cost_per_full_pie);

    // Console Output: Summary Table
    cout << "" << endl;
    cout << "Hello, " << c_name << "!" << endl << endl;
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
    cout << left << setw(50) << "Total Estimated Cost:" << "$" << d_total_cost << endl;
    cout << left << setw(50) << "Your Budget:" << "$" << d_budget << endl;
    cout << left << setw(50) << "Budget Difference (+/-):" << "$" << d_cost_difference << endl;
    cout << left << setw(50) << "Full Pies Affordable ($4 ea):" << i_pies_affordable << endl;
    cout << "==================================================================" << endl;
    cout << "                        BAKING INSTRUCTIONS                       " << endl;
    cout << "==================================================================" << endl;
    cout << "1. Peel, core, and slice the apples." << endl;
    cout << "2. Mix flour, sugar, and baking powder together in a bowl." << endl;
    cout << "3. Beat the eggs and combine with the dry mixture." << endl;
    cout << "4. Fold in the sliced apples gently into the batter." << endl;
    cout << "5. Bake at 350°F (175°C) for 35-40 minutes until golden brown." << endl;
    cout << "==================================================================" << endl;

    //  File Output: Save report and instructions to report.txt 
    ofstream outfile("report.txt");
    outfile << "==================================================================" << endl;
    outfile << "                     APPLE PIE PLANNING REPORT                    " << endl;
    outfile << "==================================================================" << endl;
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
    outfile << left << setw(50) << "Total Estimated Cost:" << "$" << d_total_cost << endl;
    outfile << left << setw(50) << "Your Budget:" << "$" << d_budget << endl;
    outfile << left << setw(50) << "Budget Difference (+/-):" << "$" << d_cost_difference << endl;
    outfile << left << setw(50) << "Full Pies Affordable ($4 ea):" << i_pies_affordable << endl;
    outfile << "==================================================================" << endl;
    outfile << "                        BAKING INSTRUCTIONS                       " << endl;
    outfile << "==================================================================" << endl;
    outfile << "1. Peel, core, and slice the apples." << endl;
    outfile << "2. Mix flour, sugar, and baking powder together in a bowl." << endl;
    outfile << "3. Beat the eggs and combine with the dry mixture." << endl;
    outfile << "4. Fold in the sliced apples gently into the batter." << endl;
    outfile << "5. Bake at 350°F (175°C) for 35-40 minutes until golden brown." << endl;
    outfile << "==================================================================" << endl;
    outfile.close();

    cout << "\n[Success] Your report and baking instructions have been successfully saved to 'report.txt'." << endl;

    return 0;
}