#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

	int day, hour, type;
	char referral;
	double base_cost = 0, surcharge = 0, total = 0;
	string slot_time;

	cout << "What type of checkup is this? (1 = General Checkup, 2 = Emergency, or 3 = Specialist).\n";
	cin >> type;

	cout << "What day is it? (1 = Monday, 2 = Tuesday, etc.)\n";
	cin >> day;

	cout << "What hour is it? (0-23)\n";
	cin >> hour;

	if (type == 1)
	{
		base_cost = 80;
		if (day == 6 || day == 7)
		{
			surcharge = surcharge + 20;
		}
		if (hour < 9)
		{
			string day_text = "??";

			switch (day)
			{
			case 1: day_text = "Mon";
				break;
			case 2: day_text = "Tue";
				break;
			case 3: day_text = "Wed";
				break;
			case 4: day_text = "Thu";
				break;
			case 5: day_text = "Fri";
				break;
			case 6: day_text = "Sat";
				break;
			case 7: day_text = "Sun";
				break;
			default: day_text = "??";
				break;
			}
			slot_time = day_text + "9:00";
		}
		else if (hour >= 9 && hour < 17)
		{
			string day_text = "??";

			switch (day)
			{
			case 1: day_text = "Mon";
				break;
			case 2: day_text = "Tue";
				break;
			case 3: day_text = "Wed";
				break;
			case 4: day_text = "Thu";
				break;
			case 5: day_text = "Fri";
				break;
			case 6: day_text = "Sat";
				break;
			case 7: day_text = "Sun";
				break;
			default: day_text = "??";
				break;
			}
			slot_time = day_text + " " + to_string(hour) + ":00";
		}
		else
		{
			int next_day = (day % 7) + 1;
			string day_text = "??";
			switch (day)
			{
			case 1: day_text = "Mon";
				break;
			case 2: day_text = "Tue";
				break;
			case 3: day_text = "Wed";
				break;
			case 4: day_text = "Thu";
				break;
			case 5: day_text = "Fri";
				break;
			case 6: day_text = "Sat";
				break;
			case 7: day_text = "Sun";
				break;
			default: day_text = "??";
				break;
			}
			slot_time = day_text + " 9:00";
		}
	}
	else if (type == 2)
	{
		base_cost = 250;
		if (hour >= 22 || hour < 6)
		{
			surcharge = surcharge + 50;
		}
		slot_time = "Immediate";
	}
	else if (type == 3)
	{
		cout << "Do you have a referral? (Y/N)\n";
		cin >> referral;
		if (referral == 'N' || referral == 'n')
		{
			surcharge = surcharge + 40;
		}
		if (day == 6 || day == 7)
		{
			slot_time = "Mon 10:00";
		}
		else
		{
			if (hour < 10)
			{
				string day_text = "??";
				switch (day)
				{
				case 1: day_text = "Mon";
					break;
				case 2: day_text = "Tue";
					break;
				case 3: day_text = "Wed";
					break;
				case 4: day_text = "Thu";
					break;
				case 5: day_text = "Fri";
					break;
				case 6: day_text = "Sat";
					break;
				case 7: day_text = "Sun";
					break;
				default: day_text = "??";
					break;
				}
				slot_time = day_text + " 10:00";
			}
			else if (hour >= 10 || hour < 16)
			{
				string day_text = "??";

				switch (day)
				{
				case 1: day_text = "Mon";
					break;
				case 2: day_text = "Tue";
					break;
				case 3: day_text = "Wed";
					break;
				case 4: day_text = "Thu";
					break;
				case 5: day_text = "Fri";
					break;
				case 6: day_text = "Sat";
					break;
				case 7: day_text = "Sun";
					break;
				default: day_text = "??";
					break;
				}
				slot_time = day_text + " " + to_string(hour) + ":00";
			}
			else
			{
				int next_day = (day % 7) + 1;

				if (next_day == 6 || next_day == 7)
				{
					next_day = 1;
				}
				string day_text = "??";
				switch (day)
				{
				case 1: day_text = "Mon";
					break;
				case 2: day_text = "Tue";
					break;
				case 3: day_text = "Wed";
					break;
				case 4: day_text = "Thu";
					break;
				case 5: day_text = "Fri";
					break;
				case 6: day_text = "Sat";
					break;
				case 7: day_text = "Sun";
					break;
				default: day_text = "??";
					break;
				}
				slot_time = day_text + " 10:00";
			}
		}
	}
	else
	{
		cout << "Invalid Service type\n";
		return 0;
	}
	total = base_cost + surcharge;

	cout << fixed << setprecision(2);
	cout << "\n--- Appointment Summary ---" << endl;
	cout << "Base cost   :$" << base_cost << endl;
	cout << "Surcharge   :$" << surcharge << endl;
	cout << "Total cost  :$" << total << endl;
	cout << "Next slot   :$" << slot_time << endl;

	return 0;

}
