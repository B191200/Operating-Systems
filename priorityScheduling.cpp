#include<bits/stdc++.h>

using namespace std;

void bubSort(vector<int> &arrival, vector<int> &burst, vector<string> & processors, vector<int> &priority) {
	int n = arrival.size();
	for(int i=0; i<n-1; i++) {
		for(int j = 0; j<n-1-i; j++) {
			if(arrival[j] > arrival[j+1]) {
				swap(arrival[j], arrival[j+1]);
				swap(burst[j], burst[j+1]);
				swap(processors[j], processors[j+1]);
				swap(priority[j], priority[j+1]);
			}
		}
	}
}

void completeTime(vector<int> &completion, vector<int> &arrival, vector<int> &burst, vector<string> &processors, vector<int> &priority) {
	
	int maxPriority = priority[0], index = 0;
	int n = arrival.size();
	
	for(int i=1; i<n; i++) {
		if(arrival[i-1] == arrival[i]) {
			if(priority[i] < maxPriority) {
				index = i;
				maxPriority = priority[i];
			}
		}
		
		else break;
	}
	
	if(maxPriority != priority[0]) {
		swap(arrival[0], arrival[index]);
		swap(burst[0], burst[index]);
		swap(processors[0], processors[index]);
		swap(priority[0], priority[index]);
	}
	
	completion.push_back(arrival[0] + burst[0]);
	
	for(int i=1; i<n; i++) {
		if(arrival[i] <= completion.back()) {
			maxPriority  = priority[i], index = i;
			
			for(int j = i; j<n; j++) {
				if(priority[j] < maxPriority) {
					index = j;
					maxPriority = priority[j];
				}
				
				else if(priority[j] == maxPriority) {
					if(arrival[j] < arrival[index]) {
						maxPriority = priority[j];
						index = j;
					} 
				}
			}
			
			if(priority[i] != maxPriority) {
				swap(arrival[i], arrival[index]);
				swap(burst[i], burst[index]);
				swap(processors[i], processors[index]);
				swap(priority[i], priority[index]);
			}
			
			completion.push_back(completion.back() + burst[i]);
			
		}
	}
	
	
	
}

void tat(vector<int>  &completion, vector<int> &arrival, vector<int> &turn) {
	for(int i=0; i<arrival.size(); i++) {
		turn.push_back(completion[i] - arrival[i]);
	}
}

void wtime(vector<int> &wait, vector<int> &turn, vector<int> &burst) {
	for(int i=0;  i < burst.size(); i++) {
		wait.push_back(turn[i] - burst[i]);
	}
}

int main() {
	int n;
	cout<<"Enter the number of processors :  ";
	cin>>n;
	
	vector<string> processors;
	vector<int> arrival;// = {0,1,2,3,4,5};
	vector<int> burst;// = {4,2,3,5,1,4};
	vector<int> priority;// = {2,4,6,3,8,7};
	cout<<endl<<"Enter arrival and Burst Timings of Processors and its Priority :  "<<endl<<endl;
	int a,b,c;
	
	for(int i=0; i<n; i++) {
		processors.push_back("P" + to_string(i+1));	
	}
	
	
	
	for(int i=0; i<n; i++) {
		cout<<"Enter Processor P"<<i+1<<" Arrival, Burst timings and Priotiy : ";
		cin>>a>>b>>c;
		arrival.push_back(a);
		burst.push_back(b);
		priority.push_back(c);
	}
	
	
	
	bubSort(arrival, burst, processors, priority);
	
	
	vector<int> completion;
	
	completeTime(completion, arrival, burst, processors, priority);
	
	vector<int> turn;
	tat(completion, arrival, turn);
	
	vector<int> wait;
	wtime(wait, turn, burst);

	cout<<endl<<endl<<"Processors"<<"    Arival time "<<"    Burst Time"<<"   Priority   "<<" Completion Time"<<"  Turn Around Time "<<" Wait Time "<<endl;
	for(int i=0; i<n; i++) {
		cout<<processors[i]<<"		"<<arrival[i]<<"		"<<burst[i]<<"            "<<priority[i]<<"  		"<<completion[i]<<" 		"<<turn[i]<<" 		"<<wait[i]<<endl;
	}
	
	cout<<endl<<"Guntt Chart : "<<endl;
	
	if(arrival[0] > 0) 
		cout<<"Ideal"<< "  ";
	
	for(int i=0; i<n; i++) {
		
		cout<<processors[i] <<" ";
	}
	
	cout<<endl<<"Average Turn Around Time : "<<accumulate(turn.begin(), turn.end(),0)/turn.size()<<endl;
	cout<<"Averate Wait Time : "<<accumulate(wait.begin(), wait.end(), 0)/turn.size()<<endl<<endl;
	
}
