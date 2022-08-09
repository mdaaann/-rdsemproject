#include<limits>
#include<bits/stdc++.h>
#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;


void welcomescreen();
int hdrscr();
int headerscreen();
class Color{ 
  public: 
         Color(int desiredColor){ 
             consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
             color = desiredColor; 
         } 
 
         friend ostream& operator<<(ostream& ss, Color obj){ 
             SetConsoleTextAttribute(obj.consoleHandle, obj.color); 
             return ss; 
         } 
  private: 
         int color; 
         HANDLE consoleHandle; 
     };
int loginsystem()
{
	ifj:
	string username;
	cout<<"\n\n\t\t\t\t\tEnter the username:- ";
 bool Enter =false;
 //while (!enter)
    cin>>username;
	char pass[30];
	char ch;
	
	int i=0;
	cout<<"\n\n\t\t\t\t\tEnter the password:- ";
//	string password;
	while(!Enter)
	{
		ch=_getch();
		        if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) {
            pass[i]=ch; //store the ch to the pass
            cout << '*';
            i++;
        }
           if (ch=='\b' && i>=1) {
            cout << "\b \b"; //to delete wrong character that user input
            i--;
        }
           if (ch=='\r') { //r is Enter or 13 charecter code (enter)
            Enter = true;
        }
		
	}
	string password(pass);
if( username=="admin"|username=="Admin" && password=="gstaff"| password=="Gstaff")
{
	return 1;
	}
	else
	{ 
	
	system("cls");
	 char haha[5];
	 char mk;
	int dap;
				{ //system("cls");
				cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t Civil Hospital service \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|    You have inserted wrong username or password                 |\n";
cout<<"\t\t\t\t\t\t|                     Choose following options                    |\n";
cout<<"\t\t\t\t\t\t|             1  >>Return to main menu                            |\n";
cout<<"\t\t\t\t\t\t|             2  >>Exit                                           |\n";
cout<<"\t\t\t\t\t\t|                                                                 |\n";
cout<<"\t\t\t\t\t\t|                                   Enter your choice..           |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
andk:cout<<"\t\t\t\t\t\t ";
cin>>haha;


	mk=haha[0];

dap=int(mk);
if(dap>50||dap<49)
{
cout<<"\n\n\t\t\t\t\t\tInvalid choice\n";
cout<<"\t\t\t\t\t\tTry again...........\n\n";
          goto andk;} 
		  //if inputed stk is other than given choi
				 switch(dap)		
				 {
				 	case '1':
				 		system("cls");
				 		welcomescreen();
				 		system("cls");
				 		goto ifj;
				 	
				 		break;
				 	case '2':
				 		exit(0);
				 	default:
				 		cout<<"\t\tInvalid choice\n";
				 		break;
				 	
				 		
				
				 }
	}
}
}
class hospitaldetail
{
	private:
		 char services[30];
		char roomno[5];
		 char hosph[12];
	public:
	hospitaldetail()
	{
		strcpy(services,"no services");
		strcpy(roomno,"noroomnumber");
		strcpy(hosph,"000");
	
		}	
	void gethospdata()
	{   cout<<Color(8)<<"\n\t\t\t\t Civil Hospital  Service"<<"\n";
		cout<<"\t\tEnter service name:- ";
		
		cin>>services;
		 for(int i=0;services[i];i++)   //validation for services
     {
     if((int(services[i])<=65)|int(services[i]>=122))
    {
    	cout<<endl<<Color(12)<<"INVALID FOUND!!! PLEASE INSERT ALPHABETS ONLY.(eg.radiology)"<<endl<<Color(8);
       cout<<"\t\tEnter  service name :";
       cin.get();

       cin.getline(services,30);

       i=0;

    }

     }
		cout<<"\n\t\tEnter the roomnp:- ";

		cin>>roomno;
		cout<<"\n\t\tEnter the room phone number:- ";
		cin>> hosph;


		 for(int i=0;hosph[i];i++)   //validation for phone number
     {
     if((int(hosph[i])<=48)|int(hosph[i]>=57)||int(hosph[i])==45)
    {
    	cout<<endl<<Color(12)<<"INVALID FOUND!!! PLEASE INSERT NUMBERS ONLY.(eg.9818199024)"<<endl<<Color(8);
       cout<<"\t\tEnter Room phone number :-";
        
       cin.get();
     
     
       cin.getline(hosph,12);
    
     
       i=0;

    }

     }
		
		
	}
	void showhospitaldata()
	{
		//cout<<"\n\t\t"<<services<<"  "<<roomno<<"  "<<hosph<<"  "<<hospitalmail<<"\n";
	     cout<<"\n***********************************************####*****************************************************************************";
	     cout<<"\n\tHospital services:"<<services;
	     cout<<"\n\tRoom number:"<<roomno;
	     cout<<"\n\tHospital room phone num:"<<hosph;
	     
	     cout<<"\n";
	
	
	
	}
 int storehosp();
 void viewalldetails();
 void updatehsdetail(char*);
 void deletehospitaldetail(char*);
 void searchospidata( char *); 
}; 
void hospitaldetail::searchospidata(char *a)
{ int counter=0;
	ifstream fin;
	fin.open("hsdetail.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\t\tfile not found"<<"\n";
	}
	else
	{
	
	fin.read((char*)this,sizeof(*this));

	while(!fin.eof())
	{
		if(!strcmp(a,services))
	{
	showhospitaldata();
	counter++;
}
	fin.read((char*)this,sizeof(*this));
			
	
	}
	fin.close();
	if(counter==0)
	{
		cout<<Color(13)<<"\t\tRECORD NOT FOUND"<<"\n"<<Color(8);
	}
}
}
void hospitaldetail::deletehospitaldetail(char *e)
{ int pos,flag=0;
ifstream fin;
fin.open("hsdetail.dat",ios::in|ios::binary);
ofstream fout;
fout.open("tempfile.dat",ios::out|ios::binary);
while(!fin.eof())
{
	fin.read((char*)this,sizeof(*this));
	if(fin)
	{
		if(!strcmp(services,e))
		{
			flag=1;
			cout<<"\t\tthe deleted data is "<<"\n";
			showhospitaldata();
		}
		else
		{
			fout.write((char*)this,sizeof(*this));
		
		}
	}
}
fin.close();
fout.close();
remove("hsdetail.dat");
getch();
rename("tempfile.dat","hsdetail.dat");
if(flag==1)
{
	cout<<Color(13)<<"\t\t\tRECORD SUCESSFULLY DELLETED"<<Color(8);
	
}
else
{
	cout<<"\t\trecord not found";
	
}

} 
 int hospitaldetail::storehosp()
 {
 	if(services=="no services"&&roomno==0)
 	{ cout<<"data not initialized";
	 }
	 else
	 { 
 	ofstream fout;
 	fout.open("hsdetail.dat",ios::app|ios::binary);
 	fout.write((char*)this, sizeof(*this));
 	fout.close();
 	return (1);
 }
 }
 void hospitaldetail::viewalldetails()
 {
 	ifstream fin;

 	fin.open("hsdetail.dat",ios::in|ios::binary);
 	if(!fin)
 	{
 		cout<<"\t\tfile not found"<<"\n";
	 }
	 else
	 {
	 
 	
 	fin.read((char*)this,sizeof(*this));
 	while(!fin.eof())
 	{
	 showhospitaldata();
	 fin.read((char*)this,sizeof(*this));
 }
 fin.close();
 }
}
  void hospitaldetail::updatehsdetail(char *t)
  {
  	
  	fstream file;
  	file.open("hsdetail.dat",ios::in|ios::out|ios::ate|ios::binary);
  	file.seekg(0,ios::beg);
  	file.read((char*)this,sizeof(*this)); 
  	while(!file.eof())
  {
	  	if(!strcmp(t,services))
  	{
  		
  		gethospdata();
  		file.seekp(-sizeof(*this),ios::cur);
  		file.write((char*)this,sizeof(*this));
	  }
	  	file.read((char*)this,sizeof(*this));
  }
  file.close();
  
  }
  
  int phmenu()
  {  
char ap[30],spp;
int hmm;
	
  	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t Civil Hospital service \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                            	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Add a hospital details                        |\n";
cout<<"\t\t\t\t\t\t|             2  >> View hospital details                         |\n";
cout<<"\t\t\t\t\t\t|             3  >> Delete hospital details                       |\n";
cout<<"\t\t\t\t\t\t|             4  >> Update hospital details                       |\n";
cout<<"\t\t\t\t\t\t|             5  >> Search hospital details                       |\n";
cout<<"\t\t\t\t\t\t|             6  >> Back                                          |\n";
cout<<"\t\t\t\t\t\t|                             Enter your choice....               |\n"; 
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
han:cout<<"\t\t\t\t\t\t ";cin>>ap;
spp=ap[0];
hmm=(int)spp;



if(hmm>54||hmm<49)
{cout<<"\n\n\t\t\t\t\t\tInvalid choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto han;} //if inputed stk is other than given stk

else
{return hmm;
}
}
  	
  class staffdetail
{
	private:
		                    char sname[32];
                            char saddress[100];
                            char scontact[12];
                            char sdeg[50];
                            char sid[10];
                            
	public:
	void staffinfo()
	{char hel[32];
		cout<<"\n\t\tStaff Name:-";
		cin.ignore();
		gets(sname);
		cout<<"\n\t\tStaff address:- ";
		gets(saddress);
		cout<<"\n\t\tStaff contact:- ";
			cin>>scontact;
			
		 for(int i=0;scontact[i];i++)   //validation for phone number
     {
     if((int(scontact[i])<=48)|int(scontact[i]>=57)||int(scontact[i])==45)
    {
    	cout<<endl<<Color(12)<<"INVALID FOUND!!! PLEASE INSERT NUMBERS ONLY.(eg.9818199024)"<<endl<<Color(8);
       cout<<"\t\tEnter Staff phone number :-";
        
       cin.get();
     
     
       cin.getline(scontact,12);
    
     
       i=0;

    }

     }
				cout<<"\n\t\tDesignation:- ";
				gets(sdeg);
				cout<<"\n\t\tStaff id:- ";
			     cin.ignore();
			     cin>>sid;
	}
	void staffdata()
	{
//cout<<"\n"<<sname<<"\t"<<saddress<<"\t"<<scontact<<"\t"<<salary<<"\t"<<sdeg<<"\t"<<sid;
    cout<<"\n***********************************######*************************************";
     cout<<"\n\tStaff id:"<<sid;   
    cout<<"\n\tStaff Name:"<<sname;
    cout<<"\n\tStaff address:"<<saddress;
    cout<<"\n\tStaff contact:"<<scontact;
    cout<<"\n\tStaff designation:"<<sdeg;
    cout<<"\n";
	}
 int sstore();
 void staffview();
 void updatestaff(char*);
 void deleteStaff(char*);
 void searchStaff(char*); 
}; 
void staffdetail::searchStaff( char *a)
{ int counte=0;
	ifstream fin;
	fin.open("sdetail.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n\t\tfile not found"<<"\n";
	}
	else
	{
	
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if((!strcmp(a,sid)||(!strcmp(a,sname))))
	  {
	staffdata();
	counte++;}
	fin.read((char*)this,sizeof(*this));
        
	}
	fin.close();
	if(counte==0)
	{
		cout<<"\n\t\RECORD NOT FOUND"<<"\n";
	}
}
}
void staffdetail::deleteStaff(char *a)
{ int pos,flag=0;
ifstream fin;
fin.open("sdetail.dat",ios::in|ios::binary);
ofstream fout;
fout.open("tempf.dat",ios::out|ios::binary);
while(!fin.eof())
{
	fin.read((char*)this,sizeof(*this));
	if(fin)
	{
		if(!strcmp(sid,a))
		{
			flag=1;
			cout<<"\n\t\tthe deleted data is "<<"\n";
			staffdata();
		}
		else
		{
			fout.write((char*)this,sizeof(*this));
		
		}
	}
}
fin.close();
fout.close();
remove("sdetail.dat");
getch();
rename("tempf.dat","sdetail.dat");
if(flag==1)
{
	cout<<"\n\t\trecord successfullly deleted";
	
}
else
{
	cout<<"\n\t\trecord not found";
}

} 
 int staffdetail::sstore()
 {
	 
 	ofstream fout;
 	fout.open("sdetail.dat",ios::app|ios::binary);
 	fout.write((char*)this, sizeof(*this));
 	fout.close();
 	return (1);
 
 }
 void staffdetail::staffview()
 {
 	ifstream fin;
 	fin.open("sdetail.dat",ios::in|ios::binary);
 	if(!fin)
 	{
 		cout<<"\n\t\tfile not found"<<"\n";
	 }
	 else
	 {
	 
 	
 	fin.read((char*)this,sizeof(*this));
 	while(!fin.eof())
 	{
	 staffdata();
	 fin.read((char*)this,sizeof(*this));
 }
 fin.close();
 }
}
  void staffdetail::updatestaff(char *t)
  {
  	
  	fstream file;
  	file.open("sdetail.dat",ios::in|ios::out|ios::ate|ios::binary);
  	file.seekg(0,ios::beg);
  	file.read((char*)this,sizeof(*this)); 
  	while(!file.eof())
  {
	  	if(!strcmp(t,sid))
  	{
  		
  		staffinfo();
  		file.seekp(-sizeof(*this),ios::cur);
  		file.write((char*)this,sizeof(*this));
	  }
	  	file.read((char*)this,sizeof(*this));
  }
  file.close();
  
  }
  int smenu()
  { 
  	char app;
int hom;
	
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t Civil Hospital service \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                            	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Add a  staff details                          |\n";
cout<<"\t\t\t\t\t\t|             2  >> View staff details                            |\n";
cout<<"\t\t\t\t\t\t|             3  >> Delete staff details                          |\n";
cout<<"\t\t\t\t\t\t|             4  >> Update  staff details                         |\n";
cout<<"\t\t\t\t\t\t|             5  >> Search staff details                          |\n";
cout<<"\t\t\t\t\t\t|             6  >> Back                                          |\n";
cout<<"\t\t\t\t\t\t|                             Enter your choice....               |\n"; 
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
had:cout<<"\t\t\t\t\t\t ";cin>>app;
hom=(int)app;
if(hom>54||hom<49)
{cout<<"\n\n\t\t\t\t\t\tInvalid choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto had;} //if inputed stk is other than given stk

else
{return app;
} 	 	
  }
  
  class patientdetail
{
	private:
		                    char  pname[20];
                            char paddress[100];
                            char pcontact[10];
                            char page[5];
                            char psex[8];
                            char pbldgp[5];
                            char pdist[50];
                            char pid[15];
                            
	public:
	void patientsinfo()
	{
		cout<<"\n\t\tPatient name:";
		cin.ignore();
		gets(pname);
		cout<<"\n\t\tPatient address:";
		gets(paddress);
		cout<<"\n\t\tPatient contact:";
			gets(pcontact);
			cout<<"\n\t\tEnter the age:";
			gets(page);
				cout<<"\n\t\tGender:";
				gets(psex);
				cout<<"\n\t\tBlood group::";
				gets(pbldgp);
				cout<<"\n\t\tDisease in past:";
				gets(pdist);
				cout<<"\n\t\tPatient id:";
			     gets(pid);
	}
	void patientsdata()
	{
//cout<<"\n"<<pname<<"\t"<<paddress<<"\t"<<pcontact<<"\t"<<page<<"\t"<<psex<<"\t"<<pbldgp<<"\t"<<pdist<<"\t"<<pid;
	cout<<"\n***********************************######*************************************";
    cout<<"\n\tPatient id:"<<pid;   
    cout<<"\n\tPatient Name:"<<pname;
    cout<<"\n\tPatient Age:"<<page;
    cout<<"\n\tPatient address:"<<paddress;
    cout<<"\n\tPatient contact:"<<pcontact;
    cout<<"\n\tGender:"<<psex;
    cout<<"\n\tBlood Group:"<<pbldgp;
    cout<<"\n\tDisease in past:"<<pdist;
    cout<<"\n";
	
	}
 int pstore();
 void pateintview();
 void updatepateint(char*);
 void deletepatient(char*);
 void searchpatient( char*); 
}; 
void patientdetail::searchpatient( char *a)
{ int countm=0;
	ifstream fin;
	fin.open("pdetail.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\t\tfile not found"<<"\n";
	}
	else
	{
	
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if((!strcmp(a,pid)||(!strcmp(a,pname))))
	  {
	patientsdata();
	countm++;}
	fin.read((char*)this,sizeof(*this));
			
	}
	fin.close();
	if(countm==0)
	{
		cout<<"\n\t\trecord not found"<<"\n";
	}
}
}
void patientdetail::deletepatient(char *a)
{ int pos,flag=0;
ifstream fin;
fin.open("pdetail.dat",ios::in|ios::binary);
ofstream fout;
fout.open("tempfil.dat",ios::out|ios::binary);
while(!fin.eof())
{
	fin.read((char*)this,sizeof(*this));
	if(fin)
	{
		if(!strcmp(pid,a))
		{
			flag=1;
			cout<<"\n\t\tthe deleted data is "<<"\n";
			patientsdata();
		}
		else
		{
			fout.write((char*)this,sizeof(*this));
		
		}
	}
}
fin.close();
fout.close();
remove("pdetail.dat");
getch();
rename("tempfil.dat","pdetail.dat");
if(flag==1)
{
	cout<<"\n\t\trecord sucessfullly deleted";
	
}
else
{
	cout<<"\n\t\trecord not found";
}

} 
 int patientdetail::pstore()
 {
	 
 	ofstream fout;
 	fout.open("pdetail.dat",ios::app|ios::binary);
 	fout.write((char*)this, sizeof(*this));
 	fout.close();
 	return (1);
 
 }
 void patientdetail::pateintview()
 {
 	ifstream fin;
 	fin.open("pdetail.dat",ios::in|ios::binary);
 	if(!fin)
 	{
 		cout<<"\n\t\tfile not found"<<"\n";
	 }
	 else
	 {
	 
 	
 	fin.read((char*)this,sizeof(*this));
 	while(!fin.eof())
 	{
	 patientsdata();
	 fin.read((char*)this,sizeof(*this));
 }
 fin.close();
 }
}
  void patientdetail::updatepateint(char *t)
  {
  	
  	fstream file;
  	file.open("pdetail.dat",ios::in|ios::out|ios::ate|ios::binary);
  	file.seekg(0,ios::beg);
  	file.read((char*)this,sizeof(*this)); 
  	while(!file.eof())
  {
	  	if(!strcmp(t,pid))
  	{
  		
  		patientsinfo();
  		file.seekp(-sizeof(*this),ios::cur);
  		file.write((char*)this,sizeof(*this));
	  }
	  	file.read((char*)this,sizeof(*this));
  }
  file.close();
  
  }
  int pmenu()
  { 
  char dpp;
int dom;
	
  cout<<"\n\n\n\n\t\t\t\t\t\t\t\t Civil Hospital service \n\n";	
cout<<"\n\n\t\t\t\t\t\t\tPlease,  Choose from the following Options:\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                            	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Add a patients details                        |\n";
cout<<"\t\t\t\t\t\t|             2  >> View patients details                         |\n";
cout<<"\t\t\t\t\t\t|             3  >> Delete patients details                       |\n";
cout<<"\t\t\t\t\t\t|             4  >> Update patients details                       |\n";
cout<<"\t\t\t\t\t\t|             5  >> Search patients details                       |\n";
cout<<"\t\t\t\t\t\t|             6  >> Back                                          |\n";
cout<<"\t\t\t\t\t\t|                             Enter your choice....               |\n"; 
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
dad:cout<<"\t\t\t\t\t\t ";cin>>dpp;
dom=(int)dpp;
if(dom>54||dom<49)
{cout<<"\n\n\t\t\t\t\t\tInvalid choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto dad;} //if inputed stk is other than given stk

else
{return dpp;
}
   }
   class workschedule
{
	private:
		                    char wname[20];
                            char wsun[700];
                            char wmon[700];
                            char wtue[700];
                            char wwed[700];
                            char wthu[700];
                            char wfri[700];
                            char wsat[700];
                            
	public:
	void workinfo()
	{
		cout<<"\n\t\tStaff Name\t";
		cin.ignore();
		gets(wname);
		cout<<"\n\t\tSunday schedule:";
		gets(wsun);
		cout<<"\n\t\tMonday schedule:";
		gets(wmon);
		cout<<"\n\t\tTueday schedule:";
		gets(wtue);
		cout<<"\n\t\tWednesday schedule:";
		gets(wwed);
		cout<<"\n\t\tThursday schedule:";
		gets(wthu);
		cout<<"\n\t\tFriday schedule:";
		gets(wfri);
		cout<<"\n\t\tSaturday schedule:";
		gets(wsat);
		
	}
	void workdata()
	{
//cout<<"\n"<<"\t\t"<<wname<<"\t"<<wsun<<"\t"<<wmon<<"\t"<<wtue<<"\t"<<wwed<<"\t"<<wthu<<"\t"<<wfri<<"\t"<<wsat;
   cout<<"\n*************************************************************************************************\n";
    cout<<"\tName:\t\t"<<wname;
	  
   cout<<"\n\n\t Day\t\t Time ";
   cout<<"\n\tSunday\t\t"<<wsun;
   cout<<"\n\tMonday\t\t"<<wmon;
   cout<<"\n\tTuesday\t\t"<<wtue;
	cout<<"\n\tWednesday\t"<<wwed;
	cout<<"\n\tThursday\t"<<wthu;
	cout<<"\n\tFriday\t\t"<<wfri;
	cout<<"\n\tSaturday\t"<<wsat;
	
	}
 int wsstore();
 void workshdview();
 void updatestaffworkshd(char*);
 void deleteStaffworkshd(char*);
 void searchStaffworkshd(char*); 
}; 
void workschedule::searchStaffworkshd( char *a)
{ int counte=0;
	ifstream fin;
	fin.open("wsdetail.txt",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n\t\tfile not found"<<"\n";
	}
	else
	{
	
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(!strcmp(a,wname))
	workdata();
	counte++;
	fin.read((char*)this,sizeof(*this));

	}
	fin.close();
	if(counte==0)
	{
		cout<<"\n\t\trecord not found"<<"\n";
	}
}
}
void workschedule::deleteStaffworkshd(char *a)
{ int pos,flag=0;
ifstream fin;
fin.open("wsdetail.txt",ios::in|ios::binary);
ofstream fout;
fout.open("wtempf.txt",ios::out|ios::binary);
while(!fin.eof())
{
	fin.read((char*)this,sizeof(*this));
	if(fin)
	{
		if(!strcmp(wname,a))
		{
			flag=1;
			cout<<"\n\t\tthe deleted data is "<<"\n";
			workdata();
		}
		else
		{
			fout.write((char*)this,sizeof(*this));
		
		}
	}
}
fin.close();
fout.close();
remove("wsdetail.txt");
getch();
rename("wtempf.txt","sdetail.txt");
if(flag==1)
{
	cout<<"\n\t\trecord successfullly deleted";
	
}
else
{
	cout<<"\n\t\trecord not found";
}

} 
 int workschedule::wsstore()
 {
	 
 	ofstream fout;
 	fout.open("wsdetail.txt",ios::app|ios::binary);
 	fout.write((char*)this, sizeof(*this));
 	fout.close();
 	return (1);
 
 }
 void workschedule::workshdview()
 {
 	ifstream fin;
 	fin.open("wsdetail.txt",ios::in|ios::binary);
 	if(!fin)
 	{
 		cout<<"\n\t\tfile not found"<<"\n";
	 }
	 else
	 {
	 
 	
 	fin.read((char*)this,sizeof(*this));
 	while(!fin.eof())
 	{
	 workdata();
	 fin.read((char*)this,sizeof(*this));
 }
 fin.close();
 }
}
  void workschedule::updatestaffworkshd(char *t)
  {
  	
  	fstream file;
  	file.open("wsdetail.txt",ios::in|ios::out|ios::ate|ios::binary);
  	file.seekg(0,ios::beg);
  	file.read((char*)this,sizeof(*this)); 
  	while(!file.eof())
  {
	  	if(!strcmp(t,wname))
  	{
  		
  		workinfo();
  		file.seekp(-sizeof(*this),ios::cur);
  		file.write((char*)this,sizeof(*this));
	  }
	  	file.read((char*)this,sizeof(*this));
  }
  file.close();
  
  }
  int wsmenu()
  { 
char adpp;
int adom;
	
    	cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                            	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Add a work shedule                            |\n";
cout<<"\t\t\t\t\t\t|             2  >> View workschedule                             |\n";
cout<<"\t\t\t\t\t\t|             3  >> Delete  workshedule                           |\n";
cout<<"\t\t\t\t\t\t|             4  >> Update  workshedule                           |\n";
cout<<"\t\t\t\t\t\t|             5  >> Search  a workshedule                         |\n";
cout<<"\t\t\t\t\t\t|             6  >> Back                                          |\n";
cout<<"\t\t\t\t\t\t|                             Enter your choice....               |\n"; 
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
adad:cout<<"\t\t\t\t\t\t ";cin>>adpp;
adom=(int)adpp;



if(adpp>54||adpp<49)
{cout<<"\n\n\t\t\t\t\t\tInvalid choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto adad;} //if inputed stk is other than given stk

else
{return adpp;
}
  }
   class attendance
{
	private:
		                    char  aname[20];
                            char sdist[50];
                            char sdate[11];
                            char sremarks[10];
                            
                            
	public:
	void atdinfo()
	{
		cout<<" \n\t\tStaff name";
		cin.ignore();
		gets(aname);
		cout<<"\n\t\tstaff position::";
		gets(sdist);
			cout<<"\n\t\tdate:";
			gets(sdate);
			cout<<"\n\t\tremarks::";
			gets(sremarks);
	}
	void atddata()
	{
//cout<<"\n"<<aname<<"\t\t"<<sdist<<"\t\t"<<sdate<<"\t\t"<<sremarks;
cout<<"\n*********************************************************************************************\n";
cout<<"\n Staff Name:"<<aname;
cout<<"\n Staff position:"<<sdist;
cout<<"\n Date:"<<sdate;
cout<<"\n Remarks:"<<sremarks;
	}
 int atdstore();
 void atdview();
 void updateatd(char*);
 void deleteatd(char*);
 void searchatd( char*); 
}; 
void attendance::searchatd( char *a)
{ int cunte=0;
	ifstream fin;
	fin.open("adetail.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n\t\tfile not found"<<"\n";
	}
	else
	{
	
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(!strcmp(a,aname))
	atddata();
	cunte++;
	fin.read((char*)this,sizeof(*this));
			
	
	}
	fin.close();
	if(cunte==0)
	{
		cout<<"\n\t\trecord not found"<<"\n";
	}
}
}
void attendance::deleteatd(char *a)
{ int pos,flag=0;
ifstream fin;
fin.open("adetail.dat",ios::in|ios::binary);
ofstream fout;
fout.open("tepfil.dat",ios::out|ios::binary);
while(!fin.eof())
{
	fin.read((char*)this,sizeof(*this));
	if(fin)
	{
		if(!strcmp(aname,a))
		{
			flag=1;
			cout<<"\n\t\tthe deleted data is "<<"\n";
			atddata();
		}
		else
		{
			fout.write((char*)this,sizeof(*this));
		
		}
	}
}
fin.close();
fout.close();
remove("adetail.dat");
getch();
rename("tepfil.dat","pdetail.dat");
if(flag==1)
{
	cout<<"\t\trecord sucessfullly deleted";
	
}
else
{
	cout<<"\n\t\trecord not found";
}

} 
 int attendance::atdstore()
 {
	 
 	ofstream fout;
 	fout.open("adetail.dat",ios::app|ios::binary);
 	fout.write((char*)this, sizeof(*this));
 	fout.close();
 	return (1);
 
 }
 void attendance::atdview()
 {
 	ifstream fin;
 	fin.open("adetail.dat",ios::in|ios::binary);
 	if(!fin)
 	{
 		cout<<"\n\t\tfile not found"<<"\n";
	 }
	 else
	 {
	 
 	
 	fin.read((char*)this,sizeof(*this));
 	while(!fin.eof())
 	{
	 atddata();
	 fin.read((char*)this,sizeof(*this));
 }
 fin.close();
 }
}
  void attendance::updateatd(char *t)
  {
  	
  	fstream file;
  	file.open("adetail.dat",ios::in|ios::out|ios::ate|ios::binary);
  	file.seekg(0,ios::beg);
  	file.read((char*)this,sizeof(*this)); 
  	while(!file.eof())
  {
	  	if(!strcmp(t,aname))
  	{
  		
  		atdinfo();
  		file.seekp(-sizeof(*this),ios::cur);
  		file.write((char*)this,sizeof(*this));
	  }
	  	file.read((char*)this,sizeof(*this));
  }
  file.close();
  
  }
  int amenu()
  { 

char adp;
int adm;
	
cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  Civil Hospital Service \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> add a attendance Record                       |\n";
cout<<"\t\t\t\t\t\t|             2  >> view all attendance record                    |\n";
cout<<"\t\t\t\t\t\t|             3  >> delete the attendance record                  |\n";
cout<<"\t\t\t\t\t\t|             4  >> update the attendance record                  |\n";
cout<<"\t\t\t\t\t\t|             5  >> search a attendance record                    |\n";
cout<<"\t\t\t\t\t\t|             6  >> Back                                          |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
dd:cout<<"\t\t\t\t\t\t ";cin>>adp;
adm=(int)adp;
if(adm>54||adm<49)
{cout<<"\n\n\t\t\t\t\t\tInvalid choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto dd;} //if inputed stk is other than given stk

else
{return adp;
}

  }
void welcomescreen()
{
hdrscr();
cout<<"\n\n\n\n\n\n\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                  WELCOME TO                                           |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                           Civil  Hospital  Service                                    |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";

system("pause");

//loginsystem();
}

int hdrscr()
{ 
	
	CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 16;
cfi.dwFontSize.X = 10;                   // Width of each character in the font
cfi.dwFontSize.Y = 21.5;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);


return 1;
}

int headerscreen()
{ 
	
	CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 20;
cfi.dwFontSize.X = 10;                   // Width of each character in the font
cfi.dwFontSize.Y = 24;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

cout << "***************************************************************CIVIL HOSPITAL SERVICE**************************************************************\n";
return 1;
}

int main()

{auy:
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
 int choik;
system("color C");
welcomescreen();
system("cls");
loginsystem();
system("cls");
char adps[30],png,hyg;
int ados;

cout<<"\t\t\t\t\t\n\n                               Login Sucessfull....                                                             \n";
ashali:
cout<<"\n\n\n\n\n\n\n\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t@@|                                          		                                  |@@\n";
cout<<"\t\t\t\t@@|           1 >> Hospital details                  		                          |@@\n";
cout<<"\t\t\t\t@@|           2 >> Staff details                              		                  |@@\n";
cout<<"\t\t\t\t@@|           3 >> Patient details                                                        |@@\n";
cout<<"\t\t\t\t@@|           4 >> Staff workshedule                                                      |@@\n";
cout<<"\t\t\t\t@@|           5 >> Staff attendance                                                       |@@\n";
cout<<"\t\t\t\t@@|           6 >> Exit                                                                   |@@\n";
cout<<"\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t@@|                        Enter your choice...                                           |@@\n";
cout<<"\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
adas:cout<<"\t\t\t\t\t\t ";cin>>adps;
hyg=adps[0];
ados=(int)hyg;



if(ados>54||ados<49)
{cout<<"\n\n\t\t\t\t\t\tInvalid choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto adas;} //if inputed stk is other than given stk

else
{png=ados;
}

system("cls");
 switch(ados)
 {
 case '1':
 {
	 	hospitaldetail h1;
	while(1)
	{ 
		switch(phmenu())
		{
		case '1':
			system("cls");
			h1.gethospdata();
			h1.storehosp();
			cout<<"record inserted"<<"\n";
			system("cls");
			break;
		case '2':
			h1.viewalldetails();
			getch();
			system("cls");
			break;
			
		case '3':
			cout<<"enter the service name to delete the record:- "<<"\n";
			char servicename[25];
			cin>>servicename;
			h1.deletehospitaldetail(servicename);
			getch();
			system("cls");
			break;
		case '4':
			cout<<"\nenter the servicename to update";
			cin>>servicename;
			h1.updatehsdetail(servicename);
			system("pause");
			break;
	   case '5':
	   	cout<<"enter the servicename to search:- ";
	   	cin>>servicename;
	   	h1.searchospidata(servicename);
	   	break;
	    case '6':
 	    	cout<<"Thank You For Your Cooperation....";
 	    	system("cls");
 	    	goto ashali;
	    	break;
	    default:
	    	cout<<"Invalid Choice";
	    	exit(0);
		}
	}
}
case '2':
	{
	
	staffdetail s1;
	
		while(1)
	{ 
		switch(smenu())
		{
		case '1':
			s1.staffinfo();
			s1.sstore();
			cout<<"record inserted"<<"\n";
			break;
		case '2':
			s1.staffview();
			getch();
			system("cls");
			break;
		case '3':
			cout<<"enter id to delete the record"<<"\n";
			char uid[14];
			cin>>uid;
			s1.deleteStaff(uid);
			break;
		case '4':
			cout<<"\nenter the id to update";
			cin>>uid;
			s1.updatestaff(uid);
			break;
	   case '5':
	   	system("cls");
			bond:
	int corn;
	char forn;   	 	
char murn;
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >>Search with staffname                          |\n";
cout<<"\t\t\t\t\t\t|             2  >>Search with staff id                           |\n";
cout<<"\t\t\t\t\t\t|                                                                 |\n";
cout<<"\t\t\t\t\t\t|                                                                 |\n";
cout<<"\t\t\t\t\t\t|                                   Enter your choice..           |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
bonds:cout<<"\t\t\t\t\t\t ";cin>>murn;
corn=int(murn);
if(corn>50||corn<49)
{cout<<"\n\n\t\t\t\t\t\tInvalid Choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto bonds;} 
//if inputed choice is other than given choice

else
 {forn=murn;
 }
	   	//cin>>ioe;
		   switch(forn)
	   	{ 
	   		case '1':
	   			cout<<"Enter staff name:";
	   			cin.ignore();
				   gets(uid);
	   				s1.searchStaff(uid);
	   			break;
	   			
	   		case '2':
			   cout<<"Enter staff id number:";
			   cin.ignore();
			   gets(uid);
			   	s1.searchStaff(uid);
			   break;
			   
	   			default:
	   				cout<<"Invalid choice";
	   				//system("cls");
	   				goto bond;
		   }//cin>>uid;
	   	//s1.searchStaff(uid);
	   	break;
	    case '6':
 	    	cout<<"Thank You For Your Cooperation....";
	    	 goto ashali;
	    	
						//exit(0);
	    default:
	    	cout<<"invalid choice";
	    	exit(0);
		}
	}
	break;	
	}
	case '3':
		{
			patientdetail p1;
			while(1)
	{ 
		switch(pmenu())
		{
		case '1':
			p1.patientsinfo();
			//system("cls");
			p1.pstore();
			cout<<"record inserted"<<"\n";
			break;
		case '2':
			p1.pateintview();
			getch();
			system("cls");
			break;
		case '3':
			cout<<"enter id to delete the record"<<"\n";
			char uid[14];
			cin>>uid;
			p1.deletepatient(uid);
			getch();
			system("cls");
			break;
		case '4':
			cout<<"\nenter the id to update";
			cin>>uid;
			p1.updatepateint(uid);
		getch();
		system("cls");
			break;
	   case '5':
	   system("cls");
		   band:
	   int dorn;
	char gorn;   	 	
char eurn;
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >>Search with patients name                      |\n";
cout<<"\t\t\t\t\t\t|             2  >>Search with patients id                        |\n";
cout<<"\t\t\t\t\t\t|                                                                 |\n";
cout<<"\t\t\t\t\t\t|                                                                 |\n";
cout<<"\t\t\t\t\t\t|                                  Enter your choice..            |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
bands:cout<<"\t\t\t\t\t\t ";cin>>eurn;
dorn=int(eurn);
if(dorn>50||dorn<49)
{cout<<"\n\n\t\t\t\t\t\tInvalid Choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto bands;} 
//if inputed choice is other than given choice

else
 {gorn=eurn;
 }
	   	//cin>>ioe;
		   switch(gorn)
	   	{ 
	   		case '1':
	   			cout<<"Enter patients name:";
	   			cin.ignore();
				   gets(uid);
	   			p1.searchpatient(uid);
	   			break;
	   			
	   		case '2':
			   cout<<"Enter patients id number:";
			   cin.ignore();
			   gets(uid);
			   	p1.searchpatient(uid);
			   break;
			   
	   			default:
	   				cout<<"Invalid choice";
	   				//system("cls");
	   				goto band;
		   }
	   	//system("cls");
	   	break;
	    case '6':
 	    	cout<<"Thank You For Your Cooperation....";
	    	 goto ashali;
	    	 break;
			//exit(0);
	    default:
	    	cout<<"invalid choice";
	    	exit(0);
		}
	}
			break;
		}
		case '4':
			{
				workschedule ws1;
				while (1)
				{
				
				switch(wsmenu())
				
		{
		case '1':
			ws1.workinfo();
			system("cls");
			ws1.wsstore();
			cout<<"record inserted"<<"\n";
			break;
		case '2':
			ws1.workshdview();//system("cls");
			getch();
			break;
			
		case '3':
			cout<<"enter id to delete the work schedule"<<"\n";
			char wid[14];
			cin.ignore();
			gets(wid);
			ws1.deleteStaffworkshd(wid);system("cls");
			break;
		case '4':
			cout<<"\nenter the id to update work schedule";
			cin.ignore();
			gets(wid);
			ws1.updatestaffworkshd(wid);system("cls");
			break;
	   case '5':
	   	cout<<"enter the staff name to search";
	   	cin.ignore();
	   	gets(wid);
	   	ws1.searchStaffworkshd(wid);system("cls");
	   	break;
	    case '6':
 	    	cout<<"Thank You For Your Cooperation....";
	    	 goto ashali;
	    	 break;
			//exit(0);
	    	
	    default:
	    	cout<<"invalid choice";
	    	exit(0);
		}
		  }
			break;	
				
				
			}
		case '5':
			{
	attendance a1;

	while(1)
	{ 		switch(amenu())
		{
		case '1':
			a1.atdinfo();
			system("cls");
			a1.atdstore();
			cout<<"record inserted"<<"\n";
			break;
		case '2':
			a1.atdview();//system("cls");
			break;
		case '3':
			cout<<"enter name to delete the record"<<"\n";
			char udi[14];
			cin.ignore();
			gets(udi);
			a1.deleteatd(udi);system("cls");
			break;
		case '4':
			cout<<"\nenter the id to update";
			cin.ignore();
			gets(udi);
			a1.updateatd(udi);system("cls");
			break;
	   case '5':
	   	cout<<"enter the name to search";
	   	cin>>udi;
	   	a1.searchatd(udi);//system("cls");
	   	break;
	    case '6':
 	    	cout<<"Thank You For Your Cooperation....";
	    	 goto ashali;
	    	 break;
			
			//exit(0);
	    default:
	    	cout<<"invalid choice";
	    	exit(0);
		}
	}break;
}
case '6':
 	    	cout<<"Thank You For Your Cooperation...."; 
			 system("cls");
	    	goto auy;
	    default:
	    	cout<<"invalid choice";
	    	exit(0);
			
}
   }

