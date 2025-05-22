#include<iostream>
using namespace std;
class expensenode;
class pricenode;
class datenode;
class idnode{
	public:
	int id;
	expensenode* next;
	idnode* nextid;
	idnode(int ID){
		id=ID;
		next=NULL;
		nextid=NULL;
	}
};
class expensenode{
	public:
	string expense;
	pricenode* next;
	expensenode(string exp){
		expense=exp;
		next=NULL;
	}
};
class pricenode{
	public:
	int price;
    datenode* next;
	pricenode(int pri){
		price=pri;
		next=NULL;
	}
};
class datenode{
	public:
	string date;
	datenode* next;
	datenode(string dat){
		date=dat;
		idnode* next=NULL;
	}
};
class linkedlist{
	idnode* head;
	public:
		linkedlist():head(NULL){
		}
		void insertatbeg(int i,string e,int p,string d){
			idnode* newid=new idnode(i);
			expensenode* newexp=new expensenode(e);
			pricenode* newpri=new pricenode(p);
			datenode* newda=new datenode(d);
			
			
			newid->next=newexp;
			newexp->next=newpri;
			newpri->next=newda;
			
			if(head==NULL){
				head=newid;
			}
			
          idnode* temp=head;
          while(temp->nextid!=NULL){
          	temp=temp->nextid;
		  }
		  temp->nextid=newid;
        }
		
		void display(){
			idnode* temp=head;
			while(temp!=NULL){
				cout<<"ID= "<<temp->id<<endl;
				expensenode* temp1=temp->next;
				if(temp1){
				  cout<<"expense= "<<temp1->expense<<endl;
				  pricenode* temp2=temp1->next;
				
					if(temp2){
				  cout<<"price= "<<temp2->price<<endl;
				  datenode* temp3=temp2->next;
				
					if(temp3){
				  cout<<"date= "<<temp3->date<<endl;
				}
			}
		}
	temp=temp->nextid;
	}
}
	void deletelinkedlist(){ 
    idnode* temp=head;
    while(temp!=NULL){
        idnode* nextid=temp->nextid;
        expensenode* exp=temp->next;
        if(exp){
            pricenode* pri=exp->next;
            if(pri){
                datenode* dat=pri->next;
                delete dat;
                delete pri;
            }
            delete exp;
        }

        delete temp;
        temp=nextid;
    }
    head=NULL;
    cout<<"linked list is deleted"<<endl;
}
   void editlinkedlist(int editid){
   	idnode* temp=head;
   	while(temp!=NULL){
   		if(temp->id==editid){
		   
   		string newexpense,newdate;
   		int newprice;
   		cout<<"enter a new expense : "<<endl;
   		cin>>newexpense;
   		cout<<"enter a new date : "<<endl;
   		cin>>newdate;
   		cout<<"enter a new price : "<<endl;
   		cin>>newprice;
   		
   		
   			expensenode* temp1=temp->next;
				if(temp1){
				  cout<<"expense= "<<temp1->expense<<endl;
				  pricenode* temp2=temp1->next;
				
					if(temp2){
				  cout<<"price= "<<temp2->price<<endl;
				  datenode* temp3=temp2->next;
				
					if(temp3){
				  cout<<"date= "<<temp3->date<<endl;
				}
			}
		}
		cout<<"linked list updated "<<endl;
		return;
	}
		temp=temp->nextid;
	   }
	 cout<<"ID not found";  
   }

};
int main(){
	linkedlist l1;
	char ch;
	
	do{
	
	cout<<"-----------EXPENSE TRACKING APP-----------"<<endl;
	cout<<"1.PRESS 1 FOR ADD NEW LINKED LIST/n "<<endl;
	cout<<"2.PRESS 2 FOR DELETE LINKED LIST/n "<<endl;
	cout<<"3.PRESS 3 FOR EDIT LINKED LIST/n "<<endl;
    cout<<"4.PRESS 4 FOR DISPLAY ALL LINKED LISTS/n "<<endl;
    cout<<"5.PRESS 5 FOR EXIT /n "<<endl;
	cout<<"Enter your choice : "<<endl;
	cin>>ch;
	
		switch(ch){
			
			case '1':{
				int id,price;
				string expense,date;
				cout<<"Enter the id:"<<endl;
				cin>>id;
				cout<<"Enter the expense:"<<endl;
				cin>>expense;
				cout<<"Enter the price:"<<endl;
				cin>>price;
				cout<<"Enter the date:"<<endl;
				cin>>date;
				l1.insertatbeg(id,expense,price,date);
				break;
			}
		    case '2':
			    l1.deletelinkedlist();
				break;
			case '3':{
				int editID;
				cout<<"Enter the ID whom you want to edit"<<endl;
				cin>>editID;
				l1.editlinkedlist(editID);
				break;
			}
			case '4':
			l1.display();
			break;
			case '5':
			cout<<"You exit the program";
			break;	
		}
			
}
while(ch!='5');
}

		
