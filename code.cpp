#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;
class Receiver {
	vector<queue<int>>sqn;
	void print(queue<int>u)
	{
		while (!u.empty())
		{
			cout << u.front() << " ";
			u.pop();
		}
		cout<<endl;
	}
public:
	void addRequestforResource(int rid, int reqno)
	{
		sqn[rid].push(reqno);

	}
	void serviceRequestatResource(int rid)
	{
		if(!sqn[rid].empty())
		sqn[rid].pop();
	}
	void printQueues()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "Queue " << i + 1 << " : ";
			print(sqn[i]);
		}
		cout << endl;
	}
	Receiver()
	{
		queue<int>u;
		for (int i = 0; i < 5; i++)
		{
			sqn.push_back(u);
		}
	}
	bool empty()
	{
		if (sqn[0].empty() && sqn[1].empty() && sqn[2].empty() && sqn[3].empty() && sqn[4].empty())
		{
			return true;
		}
		return false;
	}
};
int main()
{
	int servicing_rates[5];
	int time_control[5] = { 0,0,0,0,0 };
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the servicing rate for resource " << i + 1 << endl;
		cin >> servicing_rates[i];
	}
	Receiver obj;
	for (int i = 0; i < 100; i++)
	{
		int k = rand() % 5;
		int f = rand();
		obj.addRequestforResource(k, f);
	}
	obj.printQueues();


	int count = 0;
	while (!obj.empty())
	{
		if (time_control[0] % servicing_rates[0] == 0)
		{
			obj.serviceRequestatResource(0);
			time_control[0] = 0;
		}
		if (time_control[1] % servicing_rates[1] == 0)
		{
			obj.serviceRequestatResource(1);
			time_control[1] = 0;
		}
		if (time_control[2] % servicing_rates[2] == 0)
		{
			obj.serviceRequestatResource(2);
			time_control[2] = 0;
		}
		if (time_control[3] % servicing_rates[3] == 0)
		{
			obj.serviceRequestatResource(3);
			time_control[3] = 0;
		}
		if (time_control[4] % servicing_rates[4] == 0)
		{
			obj.serviceRequestatResource(4);
			time_control[4] = 0;
		}
		if (count % 500 == 0)
		{
			int k = rand() % 5;
			int f = rand();
			obj.addRequestforResource(k, f);
		}

		if (count % 250 == 0)
		{
			system("CLS");
			obj.printQueues();
		}

		this_thread::sleep_for(chrono::milliseconds(1));
		count++;
		time_control[0]++;
		time_control[1]++;
		time_control[2]++;
		time_control[3]++;
		time_control[4]++;
	}
	obj.printQueues();

	return 0;
}