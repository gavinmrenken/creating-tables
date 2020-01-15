//
//  table.cpp
//  Project 3
//  Created by Gavin Renken on 10/14/19.
//  Copyright © 2019 Gavin Renken. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	
	// creating variables for x and y values and assigning their values given by user 
	double x_1 = 0;				 
	double y_1 = 0;
	cout << "Enter your first x- and y-values separated by a space: ";
	cin >> x_1 >> y_1;

	// creating variables for the second x and y values and assigning their values given by user
	double x_2 = 0;				 
	double y_2 = 0;
	cout << "Enter your second x- and y-values separated by a space: ";
	cin >> x_2 >> y_2;

	// creating variables for the third x and y values and assigning their values given by user 
	double x_3 = 0;				
	double y_3 = 0;
	cout << "Enter your third x- and y-values separated by a space: ";
	cin >> x_3 >> y_3;

	// creating string that stores value of x_label given by user
	string x_label;				 
	cout << "Enter your x-label: ";
	cin.ignore();
	getline(cin, x_label);

	// creating string that stores value of y_label given by user 
	string y_label;				
	cout << "Enter your y-label: ";
	getline(cin, y_label);

	string pipe = "|"; 

	// creating integer that stores the precision value selected by the user and then setting that as the standard value 
	int precision_value = 0;	 
	cout << "What level of precision would you like? ";
	cin >> precision_value;
	setprecision(precision_value);

	cout << x_label << pipe << y_label << "\n";

	// determing the neccessary size of the dividing line based upon the size of the strings given 
	double num_dashes = 0;
	num_dashes += x_label.size();
	num_dashes += y_label.size();
	num_dashes += pipe.size();

	// makes a dividing line with dashes ---
	cout << setfill('-') << setw(num_dashes) << "\n";

	// centers the three lines of data points in the middle of the table based upon the length of the x_label given by the user 
	cout << setfill(' ') << setw(x_label.size()) << x_1 << pipe << y_1 << "\n";
	cout << setfill(' ') << setw(x_label.size()) << x_2 << pipe << y_2 << "\n";
	cout << setfill(' ') << setw(x_label.size()) << x_3 << pipe << y_3 << "\n";

	// creating value for the average between the x and y values given by the user to utlize in later calculations 
	double x_avg = 0;
	double y_avg = 0;
	x_avg = (x_1 + x_2 + x_3) / 3;
	y_avg = (y_1 + y_2 + y_3) / 3;

	// calculating slope 
	double slope = 0;
	slope = ((x_1 - x_avg) * (y_1 - y_avg) + (x_2 - x_avg) * (y_2 - y_avg) + (x_3 - x_avg) * (y_3 - y_avg)) / ((x_1 - x_avg) * (x_1 - x_avg) + (x_2 - x_avg) * (x_2 - x_avg) + (x_3 - x_avg) * (x_3 - x_avg));

	//calculating intercept for line of best fit 
	double best_fit_intercept = 0;
	best_fit_intercept = (y_avg - (slope * x_avg));

	// calculating correlation coefficent 
	double correlation_coefficient = 0;
	correlation_coefficient = ((x_1 - x_avg) * (y_1 - y_avg) + (x_2 - x_avg) * (y_2 - y_avg) + (x_3 - x_avg) * (y_3 - y_avg)) / sqrt(((x_1 - x_avg) * (x_1 - x_avg) + (x_2 - x_avg) * (x_2 - x_avg) + (x_3 - x_avg) * (x_3 - x_avg)) * ((y_1 - y_avg) * (y_1 - y_avg) + (y_2 - y_avg) * (y_2 - y_avg) + (y_3 - y_avg) * (y_3 - y_avg)));

	cout << "The best fitting equation is: y = " << slope << "x + " << best_fit_intercept << "\n";

	cout << "The correlation coefficent is: " << correlation_coefficient << "\n";

	return 0;
}
