# Metreology
This programm written in c++ is used to store data of temperature recorded daily and allows the user to request analysis of the data.
Analysis of the problem and Algorithm applied to solve, and documentation of the code.
Input Required: highest and lowest temperature for each day within a month.
Output: results for the user requests like highest and lowest temperature for the given month(year)
(Please Note: since the program is not kind of easy to write pseudocode for, I have mostly used plain English to express algorithm and provided separate analysis on every step in the documentation section)
Step 1: Start
Step 2: define and declare a 3D array named tempRecord to store a high, low and average temperature
entered by the user.
Double tempRecord[12][31][3];
Step 3: receive high and low temperature of the day using nested loops from the user and calculate.
average temperature by adding high and low temperature entered by the user and then divide by 2.
While accepting the temperature data from the user, allow the program to add temperature for all.
days in a given month and store it on the dedicated array named tempSumMonthArray[], later
divide each summation of temperature stored in this array by (number of days * 2) to get each
month’s average temperature.
tempSumMonth += tempRecord[i][j][k];
tempSumMonthArray[i] = tempSumMonth
averageMonthTemp[i] = tempSumMonth[i]/(number of days * 2);
Step 4: define and declare a function named userQueryCalling() that can ask the user’s query and display
response of that query on the screen to the user.
Step 5: define and declare a function named any_days_highest_lowest_temp() that accepts array
tempRecord as a parameter and finds the highest and lowest temperature stored for that day in the
arrays of temperature
Step 6: create a function that sorts temperature recorded in the step 3 from lowest to highest named
sortingTemperature(double array[][31][3], int x), accepts tempRecord array from step 3 and
month number to sort data for as a parameter when called sorts a data from that specific month to
get that month’s highest and lowest temperature.
Use bubble sort algorithm to sort temperature.
Step 7: define and declare a function named highest_lowest_temp_month() that accepts array tempRecord
as parameter and calls temperature sorting function sortingTemperature() by passing it’s
parameter to sort and render the value of the highest and lowest temperature for that month on the
screen with print message
Step 8: define and declare a function named highest_lowest_temp_year() that takes parameter and finds
highest and lowest temperature recorded for the whole year. Implement linear search algorithm to
find highest and lowest temperature for the year and store the indexes on which they are stored.
Step 9: define and declare a function named average_month_temp_print() that takes array named
averageTempMonth() which is defined in step 3, and the number of months the temperature is
stored for to print each month’s average temperature in the tabular format. Use for loop to iterate
through every array element passed on as a parameter.
Step 10: define and declare a function called navigateBack() that allows the user to navigate from results
of query to original query page on which user can search for any query without forcing the
program to exit the system upon entering back to query page symbol(‘*’).
Step 11: End
