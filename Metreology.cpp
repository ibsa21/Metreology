//File Name: metreology.cpp
//Author: Ibsa Abraham
   //ID No: ETS 0365/12
   //Email: ibsaabraham663@gmail.com
//Assignment Number 1
/* Description: Program to record highest and lowest temperature of the day for one year and 
respond to user queries for the temperature analysis */
// Last changed: June 28, 2021

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int i, j, k;
int monthNumber, dayNumber; 
double averageDayTemp, averageMonthTemp, highest_temp_month, lowest_temp_month, tempSumDay, tempSumMonth;

string monthsName [12] = {"Meskerem", "Tikimt", "Hidar", "Tayisas", "Tir", "Yekatit", "Megabit",
                                 "Meyaziya", "Ginbot", "Sane", "Hamile", "Nase"};

double tempRecord[12][30][3]; 
double tempSumMonthArray [12];  
double averageMonthTemperature [12];

void userQueryCalling(); 
void any_days_highest_lowest_temp(double array[][30][3]); 
void highest_lowest_temp_month(double array[][30][3]); 
void sortingTemperature (double array[][30][3], int);  
void highest_lowest_temp_year(double array[][30][3]);  
void average_month_temp_print(double array[], int);   
void navigateBack();                                   

int main()
{
    string highLowTempString [2] = {"high", "low"};
    cout << "               Ethiopian Metreology Agency \n";
    cout << "Please enter a number of  month's you would like to a store temperature for \n";
    monthWrongInput:  
    cin >> monthNumber; 
    if(!(monthNumber>=1 && monthNumber<=12)) {
    	
        cout << "Month number should be in range [1,12] \n";
        goto monthWrongInput;
    }
    
    cout << "Please enter a number of day's you would like to store a temperature for \n";
    dayWrongInput:
    cin >> dayNumber;
    if(((dayNumber >30) || (dayNumber < 1))) {
        cout << "Day number should be in range [1,30] \n";
        goto dayWrongInput;
    }

    system("cls");
    cout << "Recording temperature for " << dayNumber << " day\'s each " << monthNumber << " month. \n";
    for(i = 0; i < monthNumber; i++) {
        cout << "     Month " << i + 1 << " Temperature. \n";
        for(j = 0; j < dayNumber; j++) {
            label:
            cout << "Day " << j + 1 << " Temperature. \n";
            for ( k = 0; k < 3; k++)
            {
                if(k!=2) {
                        cout << "Enter a " << highLowTempString[k] << " temperature in " << unit <<": ";
                        cin >> tempRecord[i][j][k];
                        tempSumDay += tempRecord[i][j][k];   // adds the high and low temperature of the day
                        tempSumMonth += tempRecord[i][j][k]; // adds high and low temperatuer for the whole month
                        tempSumMonthArray[i] = tempSumMonth;  // insterts summation of the high and low month's temperature into an array
                }
                averageDayTemp = tempSumDay/2.0;  
                if(k ==2) {
                    tempRecord[i][j][k] = averageDayTemp;
                }
            }
            cout << endl;
            system("cls");

            if(tempRecord[i][j][0] < tempRecord[i][j][1]){
                    cout << "Low temperature must not not be greater than high temperature \n"
                         << "Please enter again \n";
                    goto label;
                    }
            tempSumDay = 0;
        }
        averageMonthTemp = static_cast<double>(tempSumMonth) / (dayNumber * 2);  // calculates the average month temperature for each momth
        averageMonthTemperature[i] = static_cast<double>(averageMonthTemp);      // stores average month temperature for each month on the array
        tempSumMonth = 0;
    }
    userQueryCalling();
    return 0;
}

// function that asks the user what they want to do with the data of temperature recorded
void userQueryCalling()
{
        system("cls");
    cout << "Analysis of Temperature for the year 2010\n";
    cout << "Please select \n"
         <<"[1] To Access any day's high and low temperature \n"
         <<"[2] To access any month's high, low and average temperature\n"
         <<"[3] To Access month and day with the highest temperature for the year 2010\n"
         <<"[4] To print a tabular format of average temperature for all months \n";

    cout << setprecision(1) <<fixed;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        any_days_highest_lowest_temp(tempRecord);
        break;
    case 2:  
        highest_lowest_temp_month(tempRecord);
        break;
    case 3:
        highest_lowest_temp_year(tempRecord);
        break;
    case 4:
        average_month_temp_print(averageMonthTemperature, monthNumber);
        break;
    default:
        cout << "Please enter a correct number \n";
        break;
    }
}

// a function that finds highest and lowest temperature for a given day
void any_days_highest_lowest_temp(double array[][30][3])
{
    system("cls");
    int monthChoosen, dayChoosen;
        cout << "Please enter a month \n";
        cin >> monthChoosen; 
        cout << "please enter a day \n";
        cin >> dayChoosen;

    system("cls");    
    cout << "The highest temperature recorded on " <<monthsName[monthChoosen-1] << "/" << dayChoosen << "/2010 is " <<array[monthChoosen-1][dayChoosen-1][0] << unit <<endl;
    cout << "The Lowest temperature recorded on " <<monthsName[monthChoosen-1] << "/" << dayChoosen << "/2010 is " <<array[monthChoosen-1][dayChoosen-1][1] << unit <<endl;

    navigateBack();
}

// a function that finds  highest and lowest temperature for a given month
void highest_lowest_temp_month(double array[][30][3])
{
    system("cls");
    int monthChoosen;
    cout << "Please enter a month to search for \n";
    cin >> monthChoosen;
    sortingTemperature(array, monthChoosen);  // calls the sorting function to access sorted temperature from lowest to highest
    
    system("cls");
    cout << "Highest Temperature recorded for the month " << monthsName[monthChoosen-1] << "/2010 is " << array[monthChoosen-1][dayNumber-1][2] << unit << endl;
    cout << "Lowest Temperature recorded for the month " << monthsName[monthChoosen-1] << "/2010 is " << array[monthChoosen-1][0][0] << unit<< endl;
    cout << "The average Temperature recorded for the month " << monthsName[monthChoosen-1] << "/2010 is " << static_cast<double>(averageMonthTemperature[monthChoosen-1]) << unit<< endl;

    navigateBack();
}

// a function that finds a month and day with highest and lowest temperature of the year
// linear search algorithm
void highest_lowest_temp_year(double array[][30][3])
{
    system("cls");
    int indexMax1, indexMax2, indexMin1, indexMin2; 
    highest_temp_month = array[0][0][0];  
    lowest_temp_month = array[0][0][1];
    for ( i = 0; i < monthNumber; i++)
        for ( j = 0; j < dayNumber; j++) {
                if(highest_temp_month <= array[i][j][0]) {
                    highest_temp_month = array[i][j][0];
                    indexMax1 = i;   
                    indexMax2 = j;   
                }
                if(lowest_temp_month >= array[i][j][1]) {
                    lowest_temp_month = array[i][j][1];
                    indexMin1 = i;
                    indexMin2 = j;
                }
            }

    cout << "The highest temperature of the year  is recorded on: "<< monthsName[indexMax1] << "/" << (indexMax2 + 1) << "\n"
          << "Temperature recorded: " << highest_temp_month<<unit<< endl;
    cout << "The lowest temperature of the year  is recorded on: "<< monthsName[indexMin1] << "/" << (indexMin2 + 1)  << "\n"
          << "Temperature recorded: " << lowest_temp_month <<unit<< endl;
    navigateBack();
}

// bubble sort algorithm to sort the temperature of the year in increasing order.
void sortingTemperature(double array[][30][3], int x){
    int temp;
    int max, min;
    int b, c;
         for ( j = 0 ; j < dayNumber; j++ )
             for ( k = 0 ; k < 3 ; k++ )
                    for ( b = 0 ; b < dayNumber ; b++ )
                        for ( c = 0 ; c < 3 ; c++ )
                            if (array[x-1][j][k] < array[x-1][b][c]){ 
                                temp = array[x-1][j][k];  
                                array[x-1][j][k] = array[x-1][b][c];
                                array[x-1][b][c] = temp;}
}

// prints tabular format of the average temperature for the whole year
void average_month_temp_print(double array[], int monthNumber)
{
    system("cls");
    cout << "___________________________________ \n";
    cout << "| "  << left << setw(10) << "Month" <<" | "  << "Average Temperature"  << "|\n" ;
    cout << "|____________|____________________|\n";
    for (int i = 0; i < monthNumber; i++)
    {
        cout << "| "  << left << setw(10)<< monthsName[i]<<left<<setw(6) <<" | " << array[i] << unit<< right;
        if(array[i] >=10)
            cout << setw(12);
        else
            cout << setw(13);
        cout  << " |\n";
        cout << "|____________|____________________|\n";
    }
    navigateBack();
}

// a function that helps a user to navigate back to user query page
void navigateBack()
{
    cout << "*. Back ";
    char goBack;
    cin >> goBack;
    if(goBack == '*') {
        userQueryCalling();
    }
}
/* The End */
