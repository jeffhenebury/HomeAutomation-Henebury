# HomeAutomation-Henebury

## Home Automation Course Project Overview
***In your course project, you will use the techniques and coding practices that you have learned to develop a C++ program. Each milestone assignment will include techniques taught in the earlier weeks and new techniques from the week in which the milestone is assigned. 
###Your Mission
Your company has been chosen to develop a system to control home automation. You will be working on the main program that manages smart devices in a home. They include smart thermostats, televisions, vacuum robots, lights and security systems. 
The control software is a central interface to manage all of these devices. Some functionality will be common to all of the devices. These include communications to and from the control software and the devices, and device health reports (system errors).
Device-specific functionality will allow the owner of the smart home to control each device from the central program or set up devices to be controlled by the central program through automation. For example, the central program will allow the homeowner to run a robot vacuum manually, or set appropriate times for it to be activated by the central program, without homeowner intervention. 
(NOTE: Since we will not have actual devices to control, you will need to create some simple simulation code for messages being consumed by each device, messages for device health and messages for device activation, etc. )
Smart Thermostats can be manually controlled by the homeowner or they can set up temperatures for day and evening. (To keep complexity down, we will assume only one smart thermostat and that it can only have day and evening temperatures. You are welcome to break those down by day, if desired.)
The television system may be manually controlled from the main program, turning the television on or off or changing channels. The main program can also set up the television to turn on and off based on day and time to simulate someone being home.
Lights may be manually turned off or on from the main program. ( We will limit the program to turning all lights on or off in a room to avoid complexity). 
the security system consists of an alarm and motion-activated lights. This system can be manually turned on or off or can be set to run automatically. The user shall be able to set up the time range for security system activation and the sensitivity level of the motion-activated lights. A value of 1 is least sensitive and a value of 5 most sensitive, with the intermediate range in whole numbers.***
 

###Program Requirements
Your program shall include the following, as a minimum:
Industry standard OO programming techniques for C++
Use of STL
At least one User Defined Template
Input/Output to file
Exception Handling
At least one pointer
Polymorphism 
Single Inheritance
The file structure of the program shall have the driver (main()) in its own .cpp file. Each class shall be declared in a separate .h file and implemented in its own .cpp file. 

## Notes On Implementation

Testing Data
Over the course of building the project I tested a significant amount of data. This was both ‘correct’ data to see where if the program was behaving as expected and ‘incorrect’ data to see if error and exception handling was working correctly. Examples of entered data can be found in the attached screenshots. Currently, there are no known bugs.
Requirements Breakdown
Industry standard OO programming techniques for C++
•	All ‘devices’ are broken up by class and headers.  Wherever I was able, code is stored into reusable functions.
Use of STL:
•	Several instances of vectors. There are seven Day objects stored in the WeeklySchedule vector to make a version of the week. There’s also a vector of strings in Device that holds the names of rooms that the devices operate in.
At least one User Defined Template
•	In the Device.h file, I’ve created a UDT called HoursOn. It takes in any device class as input, accesses the current weekly schedule for that device, and then picks out a day from the WeeklySchedule vector. It adds up the total number of hours that the device is on that day and returns that info to the user; I figured that would be useful information for energy efficiency.
Input/Output to file
•	I’m very excited about this addition! I’ve created a .txt file called ‘Devices.txt’ within the solution folder. It holds the daily schedule (day time on and off, nighttime on and off) for every single device. A user can make changes to the schedule via the user interface, then choose to save the changes to the file. The file will automatically open at the beginning of every new User Interface session, so the devices will ‘remember’ their schedules. This was challenging to implement but I think it adds a lot to the functionality.
Exception Handling
•	In UserInterface.cpp, I have a method called testTheInput. This implements a try/ throw/ catch block that validates user input. If the user inputs an int within the range of the device options, they continue; otherwise, an error message is thrown, the input is cleared, and they must try again.
At least one pointer
•	All the device objects use pointers in their method calls from the UserInterface class.
Polymorphism 
•	Wherever possible, the inherited classes reuse methods from the base class, Device. 
Single Inheritance
•	All the devices (i.e., vacuum, lights, etc.) are inherited from a Device base class. The inherited classes are then expanded as necessary.

*initial program open*
![intitial program open](https://user-images.githubusercontent.com/76888842/211171869-094ebcad-7843-4e7e-bff4-db0aa50a1aa0.png)

*exeption handling in main menu*
![exeption handling in main menu](https://user-images.githubusercontent.com/76888842/211171894-4a4e51ef-28c6-4d94-a2b1-09f7fb3cfa72.png)

*exeption handling in setting schedule*
![exeption handling in setting schedule](https://user-images.githubusercontent.com/76888842/211171924-101faed2-71b3-41ae-aefb-076e287c3930.png)

*setting lights schedule part 1*
![setting lights schedule part 1](https://user-images.githubusercontent.com/76888842/211171952-6fb8a114-f709-4562-9cd0-b20e4cfd586e.png)
*setting lights schedule part 2*
![setting lights schedule part 2 with UDT output](https://user-images.githubusercontent.com/76888842/211171962-1ac77a8c-eee3-40f5-850b-1054d79786a5.png)
