#include <iostream>
#include <string>
using namespace std;

	class Sensor{
		protected:
			string userName;
			string sensorModel;
			int sensorUsageLife;
			int sensorUsedDays;
			int bloodSugar;
			
			public:
				Sensor(string uN,string sM,int sUL,int sUD,int bS):userName(uN),sensorModel(sM),sensorUsageLife(sUL),sensorUsedDays(sUD),bloodSugar(bS){
				}
			virtual void checkBloodSugarLevel()=0;	//pure virtual
			
			virtual void displayRemainingUsage(){
				int remaining=sensorUsageLife-sensorUsedDays;
				if(remaining<0)								//check expired or  not
				cout<<"Sensor usage has expired"<<endl;
				else
				cout<<"Remaining usage days: "<<remaining<<endl;
			}
			
			virtual ~Sensor(){
			}
			
			void set_name(string uN){
				userName=uN;
			}
			void set_model(string sM){
				sensorModel=sM;
			}
			void set_UsageLife(int sUL){
				sensorUsageLife=sUL;
			}
			void set_UsedDays(int sUD){
				sensorUsedDays=sUD;
			}
			void set_bloodSugar(int bS){
				bloodSugar=bS;
			}
			
			string get_name(){
				return userName;
			}
			string get_model(){
				return sensorModel;
			}
			int get_UsageLife(){
				return sensorUsageLife;
			}
			int get_UsedDays(){
				return sensorUsedDays;
			}
			int get_bloodSugar(){
				return bloodSugar;
			}
	};
	
	class Dexcom:public Sensor{
		
		public:
			
			Dexcom(string uN,string sM,int sUL,int sUD,int bS):Sensor(uN,sM,sUL,sUD,bS){
				}
			
		void checkBloodSugarLevel(){
			if(bloodSugar<60)
			cout<<"Critical low blood sugar!"<<endl;
			else if(60<=bloodSugar && bloodSugar<=110 )
			cout<<"Normal blood sugar."<<endl;
			else
			cout<<"High blood sugar!"<<endl;}
			
			void displayRemainingUsage(){
				int remaining=(sensorUsageLife-sensorUsedDays)+10;
				if(remaining<0)
				cout<<"Sensor usage has expired"<<endl;
				else
				cout<<"Remaining usage days: "<<remaining<<endl;
			}
			
			~Dexcom(){
				cout<<"Destructor for "<<userName<<endl;
			}
		
	};

	class Abbott:public Sensor{
		
		public:
			Abbott(string uN,string sM,int sUL,int sUD,int bS):Sensor(uN,sM,sUL,sUD,bS){
				}
			
		void checkBloodSugarLevel(){
			if(bloodSugar<80)
			cout<<"Critical low blood sugar!"<<endl;
			else if(80<=bloodSugar && bloodSugar<=130 )
			cout<<"Normal blood sugar."<<endl;
			else
			cout<<"High blood sugar!"<<endl;}
			
			void displayRemainingUsage(){
				int remaining=(sensorUsageLife-sensorUsedDays)+7;
				
				if(remaining<0)		//check expired or  not
				cout<<"Sensor usage has expired"<<endl;
				else
				cout<<"Remaining usage days: "<<remaining<<endl;
			}
		
			~Abbott(){
				cout<<"Destructor for "<<userName<<endl;
			}
		
	};

	class Medtrum:public Sensor{
		
		public:
			Medtrum(string uN,string sM,int sUL,int sUD,int bS):Sensor(uN,sM,sUL,sUD,bS){
				}
			
		void checkBloodSugarLevel(){
			if(bloodSugar<75)
			cout<<"Critical low blood sugar!"<<endl;
			else if(75<=bloodSugar && bloodSugar<=120 )
			cout<<"Normal blood sugar."<<endl;
			else
			cout<<"High blood sugar!"<<endl;}
			
			void displayRemainingUsage(){
				int remaining=(sensorUsageLife-sensorUsedDays)+5;
				if(remaining<0)
				cout<<"Sensor usage has expired"<<endl;
				else
				cout<<"Remaining usage days: "<<remaining<<endl;
			}
			
			~Medtrum(){
				cout<<"Destructor for "<<userName<<endl;
			}
			
	};
	

int main(){

	Sensor* o[3];
	
	o[0]=new Dexcom("Naz","G7",105,130,75);
	o[1]=new Abbott("Gizem","Libre2",105,100,75);
	o[2]=new Medtrum("Yaren","S7-960",105,100,110);
	
	for(int i=0;i<3;i++){
	cout<<o[i]->get_name()<<"'s Blood Sugar Check:"<<endl;
	cout<<"Sensor Model: "<<o[i]->get_model()<<endl;
	cout<<"Testing with  blood sugar: "<<o[i]->get_bloodSugar()<<endl;
	o[i]->checkBloodSugarLevel();
	o[i]->displayRemainingUsage();
	cout<<endl<<endl;
	}
	
	for(int j=0;j<3;j++){
	delete o[j];
	}
	
	return 0;

}
