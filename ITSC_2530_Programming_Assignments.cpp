#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	// Variables definitions
    char c_name[50];
	char c_drink[50];
	char c_flavor[50];

	// Setting the console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    //Interacting with the User
    cout << "" << endl;
    cout << "░█████╗░██████╗░██████╗░██╗░░░░░███████╗░░░░░██████╗░██╗███████╗" << endl;
    cout << "██╔══██╗██╔══██╗██╔══██╗██║░░░░░██╔════╝░░░░░██╔══██╗██║██╔════╝" << endl;
    cout << "███████║██████╔╝██████╔╝██║░░░░░█████╗░░░░░░░██████╔╝██║█████╗░░" << endl;
    cout << "██╔══██║██╔═══╝░██╔═══╝░██║░░░░░██╔══╝░░░░░░░██╔═══╝░██║██╔══╝░░" << endl;
    cout << "██║░░██║██║░░░░░██║░░░░░███████╗███████╗░░░░░██║░░░░░██║███████╗" << endl;
    cout << "╚═╝░░╚═╝╚═╝░░░░░╚═╝░░░░░╚══════╝╚══════╝░░░░░╚═╝░░░░░╚═╝╚══════╝" << endl;
	cout << "" << endl;
    cout << "" << endl;

    //Name Input
    cout << "Hello!" << endl;
    cout << "Please type your name: ";
    cin >> c_name;
    cout << "" << endl;
    cout << "Hello, " << c_name << "!" << endl;
    cout << "" << endl;

    //Drink Input
    cout << "" << endl;
    cout << "What drink you would like to have with your cake? : ";
    cin >> c_drink;
    cout << "" << endl;
    cout << "" << endl;
    cout << "Nice!" << endl;
    cout << "" << endl;
	
    //Ice Cream Flavor Input
    cout << "" << endl;
    cout << "What ice cream flavor is your favorite? : ";
    cin >> c_flavor;
    cout << "Great choice!" << endl;
    cout << "" << endl;

	// Displaying the Recipe
    cout << "" << endl;
    cout << "Did you know that the simplest Apple Pie that is extremely popular on all continents, has only four main ingredients?" << endl;
    cout << "You can bake you own Apple Pie " << c_name << " in just less than an hour!" << endl;
    cout << "This cake tastes perfect with " << c_drink << " and " << c_flavor << " ice cream! " << endl;
    cout << "" << endl;
    cout << "Apple Sponge Pie Recipe" << endl;
	cout << "This apple sponge pie is perfect for any occation!" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Ingredients" << endl;
    cout << " - 3 apples" << endl;
    cout << " - 2 eggs" << endl;
    cout << " - 1 cup sugar" << endl;
    cout << " - 1 cup flour" << endl;
    cout << " - 1 tsp baking powder" << endl;
    cout << "" << endl;
    cout << "Instructions" << endl;
    cout << " 1. Preheat oven to 350°F." << endl;
    cout << " 2. Peel and slice the apples." << endl;
    cout << " 3. Beat eggs and sugar until fluffy (7 minutes minimum)." << endl;
    cout << " 4. Mix in flour and baking powder and add to the egg mixture." << endl;
    cout << " 5. Add apples and pour into a baking dish." << endl;
    cout << " 6. Bake for 35 - 40 minutes." << endl;
    cout << "" << endl;
    cout << "Serving Suggestion" << endl;
    cout << "Enjoy your apple sponge pie with " << c_flavor << " ice cream, your favorite accompaniment." << endl;
    cout << "" << endl;

    return 0;
}
