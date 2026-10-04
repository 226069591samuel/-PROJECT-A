====================================================================
               PROJECT A - GROUP CONTRIBUTION REPORTS
        MUNICIPAL FINANCIAL MANAGEMENT SYSTEM (MFMS)
====================================================================

STUDENT NAME: Malakia Iilonga
STUDENT NUMBER: 226039218
GROUP: Project A
ASSIGNED MODULE: Reports Module

MY CONTRIBUTION SUMMARY:

I was responsible for developing the Reports module for our Municipal Financial Management System. I created and worked on the reports.c and reports.h files. The main job of my module is to pull together data from all the other modules and show summary reports for the municipality.

The functions I worked on include generating summaries for total municipal employees, overall budget status, supplier details, and asset conditions. 

For Git and GitHub, I created and managed the reports-module branch. I also helped organize our repository by cleaning up extra files from branches, resolving file conflicts, and making sure my teammate's code (Searching module) had the correct author name and commit history before merging.

I tested the module by adding sample data to verify that all the reports displayed correct numbers and that the main menu integrated smoothly with my functions.

--------------------------------------------------------------------

STUDENT NAME: Elia Kwedhi
STUDENT NUMBER: 226165086
GROUP: Project A
ASSIGNED MODULE: Searching Module

MY CONTRIBUTION SUMMARY:

My assigned task in Project A was the Searching module. I developed search.c and search.h to allow users to quickly look up items across the system.

I created the SearchItem structure and wrote the searchByName() and searchById() functions. These functions allow the program to take user input and search through records by either matching unique IDs or matching full/partial names.

For GitHub, I worked on the search-module branch where my code was committed and pushed. I collaborated with my team to merge search.c and search.h into the main branch so the rest of the group could connect their modules to search.

I tested my module using different test inputs to ensure that searching for valid items returned the correct result and that searching for invalid items showed a helpful error message instead of crashing.

--------------------------------------------------------------------

STUDENT NAME: Paulina Salom
STUDENT NUMBER: 226082830
GROUP: Project A
ASSIGNED MODULE: Supplier Management & Main Menu

MY CONTRIBUTION SUMMARY:

1. Supplier Management:
I was responsible for developing the Supplier Management module. The module allows users to enter and store supplier information, display supplier details, search for a supplier by name, and compare information between two suppliers. I also tested the module using different supplier records to ensure that the functions produced the expected results.

2. Main Menu:
I was also responsible for developing the Main Menu of the Municipal Financial Management System. The menu provides access to Employee Management, Budget Management, Supplier Management, Asset Management, and Reports. It also includes an option to exit the system and handles invalid menu choices.

--------------------------------------------------------------------

STUDENT NAME: Ester Nghiwete
STUDENT NUMBER: 225021366
GROUP: Project A
ASSIGNED MODULE: Employee Management Module

MY CONTRIBUTION SUMMARY:

Employee Management module:
I was responsible for the Employee Management module. It lets the user add a new employee, display the full list of employees, search for an employee using their ID, and work out an employee's salary. I wrote four functions for this: addEmployee(), displayEmployees(), searchEmployee(), and calculateSalary(). Each employee record stores the employee ID, name, department, basic salary, housing allowance, and transport allowance. I used an array to hold up to 100 employees and a counter to keep track of how many employees have been added.

Search feature (try again):
For the search function I added a do-while loop. If the user enters an ID that does not exist, the program tells them the employee was not found and asks if they want to try again, instead of kicking them straight back to the main menu. The loop keeps running until they either find the employee or choose to stop.

GitHub contribution:
I cloned the group repository, created my own branch called employee-management, and committed my employees.c and employees.h files to that branch. I then opened a pull request (PR #1) to have my module merged into the main branch.

Testing:
I tested the module by adding a sample employee, displaying the employee list, searching for that employee by ID, and calculating their salary. I checked that the ID showed correctly, that the search found the right employee, and that the gross income (basic salary + housing allowance + transport allowance) added up to the right amount.

--------------------------------------------------------------------

STUDENT NAME: Elina Idhogela
STUDENT NUMBER: 226172031
GROUP: Project A
ASSIGNED MODULE: Budget Management Module

MY CONTRIBUTION SUMMARY:

My assigned responsibility in the group project was the Budget Management module. I developed the budget.c and budget.h files for my module. The Budget Management module allows the user to enter the number of departments, with a maximum of 10 departments, and enter the department name, allocated budget and total expenditure for each department.

I implemented validation to make sure the number of departments is between 1 and 10, the allocated budget is not less than 1000, and the total expenditure cannot be negative. I also implemented the calculation of the remaining budget by subtracting the total expenditure from the allocated budget. The program then displays a budget report for each department and indicates whether the department is within budget or has exceeded its budget.

For my GitHub contribution, I cloned the group repository, created my own branch called budget-management, added my budget.c and budget.h files, and committed them to my branch using Git. I then successfully pushed my branch to the group GitHub repository. The opened a pull request so that it could be merged into the main branch.

The validation checks in my module were confirmed in the code, including the department limit, minimum budget requirement, non-negative expenditure requirement, remaining-budget calculation, and budget status check. My responsibility was therefore to develop and prepare the Budget Management module and contribute it to the group's shared GitHub repository.

--------------------------------------------------------------------

STUDENT NAME: Samuel
STUDENT NUMBER: 226069591
GROUP: Project A
ASSIGNED MODULE: Asset Management Module & System Integration

MY CONTRIBUTION SUMMARY:

Asset Management module:
My assigned responsibility in the group project was the Asset Management module. I developed the assets.c and assets.h files for my module. The module allows the user to add an asset, display all registered assets, search for an asset, and view an asset report. Each asset record stores the asset ID, asset name, asset type, purchase value, department, and condition. I used arrays to hold up to 100 assets and a counter to keep track of how many assets have been added.

I wrote five main functions for this: assetMenu(), addAsset(), displayAssets(), searchAsset(), and assetReport(). I also wrote helper functions for reading input safely and finding assets: readString(), readInt(), readValue(), readRequired(), findAssetById(), printAsset(), and printHeader(). I used switch and do-while loops for the menus, and string functions such as strcpy(), strcmp(), strlen() and strstr() where they were needed.

Search feature:
The user can search for an asset by its exact asset ID or by the full or partial asset name. If no asset matches, the program tells the user that no asset was found.

Validation:
I implemented validation so that the asset ID cannot be empty or a duplicate of an existing ID, the asset name and department cannot be empty, the purchase value must be a valid number greater than 0, and the asset type and condition must be chosen from the menu options. Invalid menu choices, including letters, are handled without crashing the program.

Asset report:
The asset report displays all registered assets, the total number of assets, the total purchase value, and the number of assets in poor condition. The reports module can call assetReport() to include it in the system reports.

Integration & System Validation:
In addition to integration, I focused on validation. I made sure that negative salaries and budgets were not accepted, invalid menu choices were handled gracefully, and reusable validation functions were available for other modules. This improved the reliability and user-friendliness of the system. I also contributed to the GitHub repository by uploading and maintaining the main.c and main.h files, coordinating integration commits, and assisting teammates with debugging and validation before final integration.

Finally, I performed testing to verify that the main menu navigation worked correctly, input validation was effective, and all modules executed properly when integrated. My contribution ensured that the Municipal Financial Management System was functional, stable, and easy to use.
====================================================================
# Municipal Financial Management System
**Course:** Programming in Practice / System Development
**Group:** Project A

---

## 📌 Project Overview
This project is a C-based command-line application built to help local municipal offices manage daily records and operations. The system covers employee management, budget allocation, asset tracking, financial report generation, and system-wide record searching.

---

## 📂 Repository Structure & Files

| File Name | Description | Author / Lead |
| :--- | :--- | :--- |
| `main.c` | Program menu, user input handling, and module routing | Samuel |
| `reports.c` / `reports.h` | Generating financial and operational summary reports | Malakia |
| `search.c` / `search.h` | Searching records across different modules | Elia |
| `Budget.c` / `Budget.h` | Tracking municipal budgets and departmental expenditure | Paulina |
| `assets.c` / `assets.h` | Managing municipal assets and equipment inventory | Ester |
| `employees.c` / `employees.h` | Managing staff records and departmental details | Elina |

---

## 💻 How to Run the Code

### 1. Compilation
Open your terminal inside the project directory and run the GCC compiler:

```cmd
gcc -o municipal main.c reports.c search.c Budget.c assets.c employees.c
