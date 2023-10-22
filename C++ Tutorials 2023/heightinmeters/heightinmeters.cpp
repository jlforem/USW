// heightinmeters.cpp : this is a program that will take the users height in feet and inches and then coverts it to meters

   #include <iostream>
   //iomanip is included to allow the use of setprecision
   #include <iomanip>

int main()
{
    //init of all the variables needed for the inputs and calculations
    double feet = 0;
    double inches = 0;
    double meters = 0;

    //display prompt and input of the feet and inches, takes in the input for feet and inches, then displays what has been entered in feet and inches
    std::cout << "Input your height in feet and inches: \n";
    std::cin >> feet;
    std::cin >> inches;
    std::cout << "Height in feet and inches is " << feet << "ft, " << inches << "in\n";
    //calculation to convert the feet to inches and add to the current inches inputted, allows for easier covnversion in the next calculation
    inches = inches + (feet * 12);
    //calculation converting the inches to meters, uses 0.0254 as found in a conversion table at https://www.unitconverters.net/length/inches-to-meters.htm
    meters = inches * 0.0254;
    // prints out the height in meters using the iomanip function setprecision to round the meters to 3 figures, to format it the same as meters and centimeters
    std::cout << "Height in meters is " << std::setprecision(3) << meters << ".\n";
}