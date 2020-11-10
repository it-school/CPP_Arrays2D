#include <iostream>
using namespace std;

void task1()
{
	const int MONTHS = 10, COMPANIES = 8;
	int income[MONTHS][COMPANIES];

	for (size_t month = 0; month < MONTHS; month++)
	{
		for (size_t company = 0; company < COMPANIES; company++)
		{
			cout << (income[month][company] = rand() % 20) << "\t";
		}
		cout << endl;
	}
	cout << endl;

	int totalIncomeByMonth[MONTHS], totalIncomeByCompanies[COMPANIES];
	double averageIncomeByMonth[MONTHS], averageIncomeByCompanies[COMPANIES];
	double averageInCorporation = 0;

	for (size_t month = 0; month < MONTHS; month++)
		totalIncomeByMonth[month] = 0;
	for (size_t company = 0; company < COMPANIES; company++)
		totalIncomeByCompanies[company] = 0;

	for (size_t month = 0; month < MONTHS; month++)
	{
		for (size_t company = 0; company < COMPANIES; company++)
		{
			totalIncomeByMonth[month] += income[month][company];
		}
		averageIncomeByMonth[month] = (double)totalIncomeByMonth[month] / MONTHS;
	}

	cout << "totalIncomeByMonth:" << endl;
	for (size_t month = 0; month < MONTHS; month++)
	{
		cout << totalIncomeByMonth[month] << "\t";
	}

	cout << endl << "averageIncomeByMonth:" << endl;
	for (size_t month = 0; month < MONTHS; month++)
	{
		cout << averageIncomeByMonth[month] << "\t";
	}

	for (size_t company = 0; company < COMPANIES; company++)
	{
		for (size_t month = 0; month < MONTHS; month++)
		{
			totalIncomeByCompanies[company] += income[month][company];
		}
		averageIncomeByCompanies[company] = (double)totalIncomeByCompanies[company] / COMPANIES;
	}

	cout << endl;
	cout << "totalIncomeByCompanies:" << endl;
	for (size_t company = 0; company < COMPANIES; company++)
	{
		cout << totalIncomeByCompanies[company] << "\t";
	}

	cout << endl << "averageIncomeByCompanies:" << endl;
	for (size_t company = 0; company < COMPANIES; company++)
	{
		cout << averageIncomeByCompanies[company] << "\t";
	}

	for (size_t company = 0; company < COMPANIES; company++)
	{
		averageInCorporation += averageIncomeByCompanies[company];
	}
	averageInCorporation /= COMPANIES;
	cout << endl << "averageInCorporation: " << averageInCorporation << endl;

	cout << "Companis with income more than average in corporation:" << endl;
	for (size_t company = 0; company < COMPANIES; company++)
	{
		if (averageIncomeByCompanies[company] > averageInCorporation)
			cout << company << ") " << averageIncomeByCompanies[company] << endl;
	}

	cout << endl;

	int maxMonth = 0, maxCompany = 0;
	int minMonth = 0, minCompany = 0;
	for (size_t company = 0; company < COMPANIES; company++)
	{
		for (size_t month = 0; month < MONTHS; month++)
		{
			if (income[company][month] > income[maxCompany][maxMonth])
			{
				maxCompany = company;
				maxMonth = month;
			}
			//else
			{
				if (income[company][month] < income[minCompany][minMonth])
				{
					minCompany = company;
					minMonth = month;
				}
			}
		}
	}
	cout << "Max income in corporation is: " << income[maxCompany][maxMonth] << endl;
	cout << "Min income in corporation is: " << income[minCompany][minMonth] << endl;

	int maxCounter = 0, minCounter = 0;
	for (size_t company = 0; company < COMPANIES; company++)
	{
		for (size_t month = 0; month < MONTHS; month++)
		{
			if (income[maxCompany][maxMonth] == income[company][month])
			{
				maxCounter++;
			}
			// TODO: Correct min counter
			if (income[minCompany][minMonth] == income[company][month])
			{
				minCounter++;
			}
		}
	}

	cout << "Max income in corporation found: " << maxCounter << " times" << endl;
	cout << "Min income in corporation found: " << minCounter << " times" << endl;

	cout << endl << "Sort by row Total Income by Company (totalIncomeByCompanies):" << endl;
	for (size_t company = 0; company < COMPANIES; company++)
	{
		cout << totalIncomeByCompanies[company] << "\t";
	}

	int temp;
	for (size_t month = 0; month < MONTHS; month++)
	{
		for (size_t company = 0; company < COMPANIES - 1; company++)
		{
			if (totalIncomeByCompanies[company] < totalIncomeByCompanies[company + 1])
			{
				temp = totalIncomeByCompanies[company];
				totalIncomeByCompanies[company] = totalIncomeByCompanies[company + 1];
				totalIncomeByCompanies[company + 1] = temp;

				for (size_t submonth = 0; submonth < MONTHS; submonth++)
				{
					temp = income[submonth][company];
					income[submonth][company] = income[submonth][company + 1];
					income[submonth][company + 1] = temp;
				}
			}
		}
	}

	cout << endl << endl;
	for (size_t company = 0; company < COMPANIES; company++)
	{
		cout << totalIncomeByCompanies[company] << "\t";
	}

	cout << endl << endl;
	for (size_t month = 0; month < MONTHS; month++)
	{
		for (size_t company = 0; company < COMPANIES; company++)
		{
			cout << income[month][company] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	task1();
}