# shopping-complex-management-system

#include<iostream>
#include<string>
#include<sstream>
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int search(int);
int display();
string check(int);

//Structure Bucket is used as a stack for the trolly number
struct bucket
{ 
	int data; 
   	bucket* link; 
};     
struct bucket* top; 
 
void push(int data) 
{  
	struct bucket* temp; 
	temp = new bucket(); 
	if (!temp) 
	{ 
		cout << "\nHeap Overflow"; 
		exit(1); 
	} 
	temp->data = data; 
	temp->link = top; 
	top = temp; 
} 

int isEmpty() 
{ 
	return top == NULL; 
} 

int peek() 
{ 
	if (!isEmpty()) 
		return top->data; 
	else
		exit(1); 
} 

void bpop() 
{ 
	struct bucket* temp; 
	if (top == NULL) 
	{ 
		cout << "\nStack Underflow" << endl; 
		exit(1); 
	} 
	else 
	{ 
		cout<<"Your cart No is :"<<top->data<<endl; 
		cout<<"                  __"<<endl;
		cout<<"                 /  |_"<<endl;
		cout<<"  ______________/    "<<endl;
		cout<<" |             |     "<<endl;     
		cout<<" |             |     "<<endl;     
		cout<<" |_____________|     "<<endl;     
		cout<<"    _______/         "<<endl;
		cout<<"     O   O           "<<endl;
		temp = top; 
		top = top->link;  
		temp->link = NULL;
		free(temp); 	
	}
	
} 

void bdisplay() 
{ 
	struct bucket* temp; 
	if (top == NULL) 
	{ 
		cout << "\nStack Underflow"; 
		exit(1); 
	} 
	else
	{
		temp = top; 
		while (temp != NULL)
		{ 
			cout << temp->data << " ";  
			temp = temp->link; 
		} 
	} 
} 

// Structure of Node used a queue for storing details of the customers.
struct Node
{ 
    string cname;
	long long int contact;
	int amount;
    Node *link;
};

Node *front = NULL;
Node *rear = NULL;

//To check if queue is empty or not
bool isempty()
{
    if(front == NULL && rear == NULL)
    return true;
    else
    return false;
}

//To enter elements in queue
void enqueue(string name,long long int cont,int amou)
{
    Node *ptr = new Node();
    ptr->cname=name;
	ptr->contact=cont;
	ptr->amount=amou;
    ptr->link = NULL;

    //For inserting the first element
    if( front == NULL )
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear ->link = ptr;
        rear = ptr;
    }
}

//To delete  a single element from queue
void dequeue()
{
    if(isempty())
    {
		cout<<"Queue is empty\n";
	}
    else
    {
        if( front == rear) 
		//For only single element in the queue
        {
            free(front);
            front = rear = NULL;
        }
        else
        {
            Node *ptr = front;
            front = front->link;
            free(ptr);
        }
    }
}

//function to show the element at front
void showfront()
{
    if(isempty())
	{
    	cout<<"Queue is empty\n";
	}
    else
    {
		cout<<"element at front is:"<<front->cname<<"\t"<<front->contact<<"\t"<<front->amount<<"\n";
	}
}

//function to display full queue
void displayQueue()
{  
    if (isempty())
    cout<<"Queue is empty\n";
    else
    {
		cout<<"\t\tCUSTOMERS NAMES LIST\n\n";
		cout<<"\tName\t\t\tContactNumber\tAmount\n";
        Node *ptr = front;
        while( ptr !=NULL)
        {
            cout<<"\t"<<ptr->cname<<"\t"<<ptr->contact<<"\t"<<ptr->amount<<endl;
            ptr= ptr->link;
        }
    }
}

//Linked list for storing data of the available items in the store
struct node
{
	int ID;
	string proName;
	double prePrice;
	int quantity;
    struct node* next;
};
struct node *head=NULL;

//Funtion to add a new item to the store
void add()
{
	system("cls");
	int id,quan;           
	string name;
	double pre;           
	struct node *t=new node;
	struct node *p=head;
	cout<<"\t\t\tEnter product ID : ";
	cin>>id;
	t->ID=id;
	cout<<"\t\t\tEnter product Name : ";
	cin.ignore();
	getline(cin,name);
	t->proName=name;
	cout<<"\t\t\tEnter product price : ";
	cin>>pre;
	t->prePrice=pre;
	cout<<"\t\t\tEnter product quantity : ";
	cin>>quan;
	t->quantity=quan;
	if(head==NULL)
	{
		t->next=head;
		head=t;
	}
	else
	{
		while(p->next!=NULL)
    	{
			p=p->next;
		}
        p->next=t;
        t->next=NULL;
	}	
	system("cls");
    cout<<"\n\n\t\t\t\tThis product is Inserted!\n\n\n";
}

//for searching item in list
int search(int id)
{
 	int count=1;
 	struct node *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 			break;
 		else
 			count++;
 			p=p->next;
	}
 	return count;
}

//For deleting a item from the list
void delPro()
{
	system("cls");
	display();
	int id;
	struct node *cur=head;
	struct node *pre=head;
	cout<<"\n\n\t\tEnter ID to delete that product:\n\n";
	cin>>id;
    if (head == NULL)
    {
    	system("cls");
        cout<<"\tList is empty"<<endl;
    }
	int pos=0;
	int count=display();
	pos=search(id);
	if(pos<=count)
	{
		while(cur->ID!=id)
		{                
			pre=cur;
			cur=cur->next;
		}
		pre->next=cur->next;
		system("cls");
		cout<<"\n\tItem is deleted from the inventory\n";
	}
	else
	{
		cout<<"\n\tNot found in the inventory\n\n";
	}
}

//For modifying the Item details in the list
void modify()
{
	int id;
	double pre;
	string pName;
	int nid,nq;
	if (head == NULL)
	{
		system("cls");
		cout<<"\tList is empty"<<endl;
	}
	else
	{    
		display();
		cout<<"\n\n\tEnter ID to modify product Name and price:\n";
		cin>>id;
		struct node *cur=head;
		int pos=0;
		int count=display();
		pos=search(id);
		if(pos<=count)
		{
			while(cur->ID!=id)
			{
				cur=cur->next;
			}
			cout<<"\n\tOld ID : "<<cur->ID<<endl;
			cout<<"\n\tOld Name : "<<cur->proName<<endl;
			cout<<"\n\tOld Price : "<<cur->prePrice<<endl;
			cout<<"\n\tOld Quantity : "<<cur->quantity<<endl;
			cout<<endl<<endl;
			cout<<"Enter new ID : ";
			cin>>nid;
			cur->ID=nid;
			cout<<"Enter new Name : ";
			cin>>pName;
			cur->proName=pName;
			cout<<"Enter new Price : ";
			cin>>pre;
			cur->prePrice=pre;
			cout<<"Enter new Quantity : ";
			cin>>nq;
			cur->quantity=nq;
		}
		else
		{
			cout<<id<<" is not found in the inventory\n\n";
		}
	}
}

//For update quantity of a product
void update()
{
	int id;
	int nquantity;
	if (head == NULL)
	{
		system("cls");
		cout<<"\tList is empty"<<endl;
	}
	else
	{    
		display();
		cout<<"\n\n\tEnter ID to update product Quantity:\n";
		cin>>id;
		struct node *cur=head;
		int pos=0;
		int count=display();
		pos=search(id);
		if(pos<=count)
		{
			while(cur->ID!=id)
			{
				cur=cur->next;
			}
			cout<<"\n\tOld ID : "<<cur->ID<<endl;
			cout<<"\n\tOld Name : "<<cur->proName<<endl;
			cout<<"\n\tOld Price : "<<cur->prePrice<<endl;
			cout<<"\n\tOld Quantity : "<<cur->quantity<<endl;
			cout<<endl<<endl;
			cout<<"Enter new Quantity : ";
			cin>>nquantity;
			cur->quantity=nquantity;
		}
		else
		{
			cout<<id<<" is not found in the inventory\n\n";
		}
	}

}
//For displaying the Total items in the list
int display()
{
	system("cls");
	int c=0;
	struct node *p=head;
	cout<<"Existing products are:\n";
	cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
	cout<<"=================================================================|\n";
	while(p!=NULL)
	{
		cout<<p->ID<<"\t\t"<<p->proName<<"\t\t\t"<<p->prePrice<<"\t\t"<<check(p->quantity)<<"\n";
		p=p->next;
		c=c+1;
	}
	cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
	return c;
}

//check function for checking the quantity status a a product
string check(int quant)
{              
    int a = quant;
    stringstream ss;
    ss << a;
    string quantity = ss.str();
   	if(quant<=0)
   	return "out of stock!";
   	else
   	return quantity;
}

//Function for customers for their buying order
void buy()
{
    system("cls");
    display();
    string products[20];
	int pay=0,no,c=0,price,id,i=1;
    if(head==NULL)
    {
	    cout<<"\n\tThere is no items to buy\n\n";
		system("pause");
    }
    else
    {
		cout<<"How many Products you wanna to buy!\n";
		cin>>no; 
        int count=display();          
		while (i<=no)
        {
			struct node *cur=head;
            int quan;   
			label: 
            cout<<"\nEnter id of item that you want to buy:              (if dont want anything enter '-1')\n";
            int id,pos=0;
            cin>>id;
            if(id==-1)
			{
				system("cls"); 
				return;	
			}
	        pos=search(id);
	        if(pos<=count)
	        {
				while(cur->ID!=id)
				{
					cur=cur->next;
				}
				cout<<"\n\t\tHow many quantities you want:";
				cin>>quan;
				if(cur->quantity<quan)
				{
					cout<<"\n\n\t\tThe Quantity You Entered is not available at the moment"<<endl;
					cout<<"\n\t\tPress any key to go back to the Menu..."<<endl;
					goto label;
				}
				products[c]=cur->proName;   
				c++;   
				pay=pay+(cur->prePrice*quan);        
				cur->quantity=cur->quantity-quan;      
				cout<<"\n\t\tTotal items : "<<i;
				cout<<"\n\t\tTotal Amount : "<<pay;
				i++;
			}
			else
			{         
				cout<<"\n\t\tThis item is not available in our store at this time\n\n";
			}
		}
		string customer;
		cout<<"\n\t\tEnter Your Name :"; 
		cin.ignore();
		getline(cin,customer);
		cout<<"\n\t\tEnter Your Contact Number : ";
		long long int cont;
		cin>>cont;
		price=pay*(0.90);
		enqueue(customer,cont,price);
		system("cls");
		cout<<"\n\n\n\n\t\tYou have bought : ";
		for(int i=0;i<no;i++)
		{           
			cout<<products[i]<<",";
		}       
		cout<<"\n\nOriginal price : "<<pay;
		cout<<"\n with 10% discount: "<<price<<"\nThank you! for the shopping\n\n";
	}
}

void addcart()
{
	int a=peek();
	cout<<"Total no. of cart : "<<a;
	cout<<"\nEnter the number of cart to add to the store : ";
	int add;
	cin>>add;
	for(int i=1;i<=add;i++)
	{
		push(a+i);
	}
	a=peek();
	cout<<"Total no. of cart now : "<<a<<endl;
}
//Administrator main function
void administator()
{
	system("cls");
	int ch;
	do 
	{
		cout<<"\t\t__________________________________________________\n"<<endl;
		cout<<"\t\t               Administator Portal                "<<endl;
		cout<<"\t\t__________________________________________________"<<endl;
		cout<<"\t\t     Enter 1 to ADD a new product    "<<endl;
		cout<<"\t\t     Enter 2 to DISPLAY all products   "<<endl;
		cout<<"\t\t     Enter 3 to MODIFY Existing product"<<endl;
		cout<<"\t\t     Enter 4 to DELETE a particular product item"<<endl;
		cout<<"\t\t     Enter 5 to UPDATE quantity of a product item"<<endl;
		cout<<"\t\t     Enter 6 to VIEW the Customers List "<<endl;
		cout<<"\t\t     Enter 7 to DEQUEUE customer list "<<endl;
		cout<<"\t\t     Enter 8 to ADD carts to the store "<<endl;
		cout<<"\t\t     Enter 0 to go back to Main Menu"<<endl;
		cout<<"\n\t\tEnter Your choice : ";   
		cin>>ch;
		switch(ch)
		{
			case 1:
				add();
				break;
			case 2:
				system("cls");
				display();
				break;
			case 3:
				modify();
				system("cls");
				break;
			case 4:
				delPro();
				cout<<"\n\t\tProduct is Deleted\n";
				break;
			case 5:
				system("cls");
				update();
				break;
			case 6:
				system("cls");

				displayQueue();
				break;
			case 7:
				system("cls");
				dequeue();
				displayQueue();
				break;
			case 8:
				system("cls");
				addcart();
				break;
			default: 
			system("cls");
		}
	}
	while(ch!=0)	;
}


int main()
{
	for(int i=0;i<=50;i++)
    {
		push(i);
	}
	system("cls");
	cout<<"\t\t\t__________________________________________________\n"<<endl;
	cout<<"\t\t\t             MAXX SHOPPING COMPLEX                "<<endl;
	cout<<"\t\t\t__________________________________________________"<<endl;
   	cout<<"\n\n\t\t\tBY:-"<<endl;
   	cout<<"\t\t\tKanishk tayal (2K20/IT/67)"<<endl;
   	cout<<"\t\t\tKrittin nagar (2K20/IT/76)"<<endl<<endl;
	cout<<"\n\n\t\t\tSubmitted to : Ritu Ma'am\n\n\t\t\t";
	system("pause");
	system("cls"); 
    int ch;
	while(ch!=3)
	{
		system("cls");
		cout<<"\n\t\t_______________________________\n";
		cout<<"\n\t\t            Main Menu          ";
		cout<<"\n\t\t_______________________________";
		cout<<"\n\t\t 1) Administation of the Store";
		cout<<"\n\t\t 2) Customer";
		cout<<"\n\t\t 3) Exit";
		cout<<"\n\n\t\t Enter Your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				administator();
				break;
			case 2:
				cout<<"\n\n";
				bpop();
				bdisplay();
				system("pause");
				buy();
				break;
			case 3:
				cout<<"\n\n\t\tThank You\t\t\t\t\n\n";
				break;
		}
	}
	return 0;	
}
