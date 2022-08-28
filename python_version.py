#initial monthNumber and dayNumber;
monthNumber = int(input('Month Number'))
dayNumber = int(input('day Number'))

monthsName = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']

print(len(monthsName))
yearDataContainer = []
average_temp_container = []
high_temp = 0
low_temp = 0
average_temp = 0

def enterTemperature(beginMonth, endMonth, endDay):
    temp_sum = 0
    monthCounter = beginMonth
    while monthCounter < endMonth:
        print(monthCounter)
        dayCounter = 0
        dataContainer = []
        while (dayCounter < endDay):
            print(dayCounter)
            listCounter = []
            temp_condition = True
            while temp_condition:
                low_temp = int(input("Enter low temperature"))
                high_temp = int(input("Enter high temperature"))
                if(high_temp > low_temp):
                    average_temp = (high_temp + low_temp) /2
                    temp_condition = False
                else:
                    print('high temperature should not be less than low temperature')

                listCounter.append(low_temp)
                listCounter.append(average_temp)
                listCounter.append(high_temp)
                temp_sum +=high_temp + low_temp

                dataContainer.append(listCounter)
                listCounter  = []
                dayCounter = dayCounter + 1

        yearDataContainer.append(dataContainer)
        average_temp_container.append(temp_sum/(dayNumber * 2))
        temp_sum = 0
        dataContainer = []
        monthCounter = monthCounter + 1
    print(yearDataContainer)

enterTemperature(0, monthNumber, dayNumber)

#monthnumber and dayNumber for later use
newMonthNumber = 0
newDayNumber = 0      
def enterNewTemperature():
            newMonthNumber = int(input('Enter a number of months you would like to add'))  
            newDayNumber = int(input("Enter number of days"))
            global totalMonthNumber 
            global totalDayNumber
            totalMonthNumber= monthNumber + newMonthNumber
            totalDayNumber = dayNumber + newDayNumber
            print(totalMonthNumber)
            print(totalDayNumber)
            enterTemperature(monthNumber, (totalMonthNumber), newDayNumber )

def queryList():
    """User requests"""
    print("Choose from the following requersts\n")
    print("[1] To search for any day's high and low temperature")
    print("[2] To search for any month's high, low and average temperature")
    print("[3] To search for month and day with highest and lowest  temperature")
    print("[4] To print all months temperature in tabular format")
    print("[5] To Enter a temperature again")    
    print("[0] To quit")    

    selected = int(input("Your choice: "))
    return selected


def days_high_low_temp():
    """Any Day's highest lowest and average temperature"""
    month = int(input("Enter a month to search for"))
    day = int(input("Enter a day to search for"))
    if(month <= totalMonthNumber and day <= totalDayNumber):
        monthTempContainer = yearDataContainer[month-1]
        dayDataContainer = monthTempContainer[day-1]
        print(f'High Temp: {dayDataContainer[2]}')
        print(f'Low Temp: {dayDataContainer[0]}')
        print(f'Average Temp: {dayDataContainer[1]}')
    else:
        print("Temperature does not exit for date requested")


def months_high_low_temp():
    """Searching for any month's high, low and average temperature"""
    month = int(input("Enter a month"))
    if(month <=totalMonthNumber):
        monthTemperatures = yearDataContainer[month-1]
        for monthTemperature in monthTemperatures:
            monthTemperature.sort()
            
        highest_temperature = monthTemperatures[-1]
        lowest_temperature = monthTemperatures[0]
        print(f'High Temperatuare: {highest_temperature[-1]}')
        print(f'Lowest Temperatuare: {lowest_temperature[-1]}')
    

def year_highest_lowest_temp():
    """finding highest and lowest temperature of a year"""
    yearTemperature = []
    for monthsTemperature in yearDataContainer:
        for daysTemperature in monthsTemperature:
            for temperature in daysTemperature:
                yearTemperature.append(temperature)

    yearTemperature.sort()
    print(f'Highest temperature of a year is {yearTemperature[-1]}')
    print(f'Lowest temperature of a year is {yearTemperature[0]}')

def print_tabular():
    """To print all months temperature in a tabular format"""
    print("Month\tAverage Temperature")
    counter = 0
    while counter < totalMonthNumber:
        print(f'{monthsName[counter]}\t\t{average_temp_container[counter]}')
        counter = counter + 1
    
def response_to_request():
    """Responding to user requests"""
    condition = True
    while condition:
        requestID = queryList()
        if(requestID==1):
            days_high_low_temp()
        elif(requestID==2):
            months_high_low_temp()
        elif(requestID==3):
            year_highest_lowest_temp()
        elif(requestID==4):
            print_tabular()
        elif(requestID==5):
            enterNewTemperature()
        else:
            condition = False
            
response_to_request()