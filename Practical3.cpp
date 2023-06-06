#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct node
{  
        char name[20];
    	 node *next;   //next chapter next section 
     	 node *down;   //Chapter -> scetion -> subsection
     	 int flag;      //wheather that node is having section or not
};

class Gll
{   
          char ch[20]; 
          int n,i;    
    	  node *head=NULL,*temp=NULL,*t1=NULL,*t2=NULL;   // created pointers of struct node
   	  public:
    		node *create();  // to create node
   		void insertb();
    		void insertc();
     		void inserts();
     		void insertss();
     		void displayb();    // display tree
};


node *Gll::create()
{
 	node *p=new(struct node);    //p= new node means p has name next down and flag created
   	p->next=NULL;
   	p->down=NULL;             
   	p->flag=0;
    	cout<<"\n enter the name";
    	cin>>p->name;                      //every time we insert node then that create function will write that node
  	return p;              // created node
}

void Gll::insertb()
{      
         if(head==NULL)    //if No node created
           { 
                t1=create();
                head=t1;             //create t1 and make this to head node
           }
        else               // if book node alreadycreated
           {
              cout<<"\n book exist";
           }   
}     

void Gll::insertc()
{     
           if(head==NULL)  //if there is no book then print 
         	 { 
                  	cout<<"\n there is no book";   
          	 }
           else
           	{    
                  cout<<"\n how many chapters you want to insert";
                  cin>>n;
                  for(i=0;i<n;i++)
                      {
               		 t1=create();
                	 if(head->flag==0)   // if flag==0 then no chapter under this node
                		{  
                                 head->down=t1;
                                 head->flag=1;    
}
               		    else               //else flag==1 then
               		       {  
                                        temp=head;
                   			temp=temp->down;    //find down postioon until next chapter get null
                   			 while(temp->next!=NULL)
                         			temp=temp->next;
                    			 temp->next=t1;    //once we get Null assign t1
               		 }
               	 }
          }                        
} 
void Gll::inserts()
{     
  
        	 if(head==NULL)
          	{ 
                 	 cout<<"\n there is no book";   
        	   }
           	else
         	  {    
                        cout<<"\n Enter the name of chapter on which  you want to enter the section";
                 	cin>>ch;
                	temp=head;
              		if(temp->flag==0)
               	{  
                         cout<<"\n their are no chapters on in book";
               	}
                 	else
              		 {    
                                temp=temp->down;
                		while(temp!=NULL)
                 		{ 
                      		if(!strcmp(ch,temp->name))   // name of chapter is same as we given as chapter compare
                      		{   
                                	 cout<<"\n how many sections you want to enter";
                              		 cin>>n;
                              		 for(i=0;i<n;i++)
                             			{
                                          	         t1=create();  // create node for each section
                                              		 if(temp->flag==0) // no section  are created under chapter
                                              		 {     
                                                                        temp->down=t1;  //create section
                                         				temp->flag=1;  
                                                                          cout<<"\n******";
                                                        	           t2=temp->down;
                                              		 }
                                              		else                 // if already section available
                                              		 {           
                                                              		cout<<"\n#####";
                                                              		 while(t2->next!=NULL) 
                                                               		{    
                                                                                  t2=t2->next;   // search for next null node   
 }
                                                                     		  t2->next=t1;    //insert node at next location           
                                                		         }   
                                		          }                                
                                 	  	            break;       
                    	   	          }  
                                 	temp=temp->next;    //we have to search next match if ch is not matched
                  	      }  //end of while
                      }  //else  
              } //else
}
void Gll::insertss()
{     
         if(head==NULL)
          { 
                  	cout<<"\n there is no book";   
           }
           else
           {   
 cout<<"\n Enter the name of chapter on which  you want to enter the section";
                 	cin>>ch;
temp=head;
               	if(temp->flag==0)
              		 {   
cout<<"\n their are no chapters on in book";
             		  }
               	else
              		 {    
temp=temp->down;
                		while(temp!=NULL)
                		 { 
                     			 if(!strcmp(ch,temp->name))
                      			{       
cout<<"\n enter name of section in which you want to enter the sub section";
                         				cin>>ch;
if(temp->flag==0)
                        				{  
 cout<<"\n their are no sections ";  
 }
                        
 else
                        				 {       
temp=temp->down;
                                 			while(temp!=NULL)
                                 			{
                                     				if(!strcmp(ch,temp->name))
                                   				{
cout<<"\n how many subsections you want to enter";
                                        				cin>>n;
                   					 for(i=0;i<n;i++)
                                  				 {
 							t1=create();
                                             				 if(temp->flag==0)
                                              				 {      
temp->down=t1;
                                                     					 temp->flag=1;  cout<<"\n******";
                                                       					 t2=temp->down;
                                                   				 }
                                            					 else
                                             				  {           
                                                              				cout<<"\n#####";
                                                               				while(t2->next!=NULL)
                                                            				  {   
  t2=t2->next;  
  }
                                                                       				t2->next=t1;                 
                                                				 }   
                                     				   }                              
                                        				 break;
                                   			  }      
temp=temp->next;
                                  		 	}
                        			  }       
                       		}
temp=temp->next;
                	  }
                }    
         }
} 
void Gll::displayb()
{       
if(head==NULL)
                {  
cout<<"\n book not exist"; 
                }
                else
                {
                 	temp=head;
cout<<"\n NAME OF BOOK:  "<<temp->name;
                        	 if(temp->flag==1)
                         	{
                         		temp=temp->down;
                        
                          		 while(temp!=NULL)
                           		{     
cout<<"\n\t\tNAME OF CHAPTER:  "<<temp->name;
                                t1=temp;
                                		 if(t1->flag==1)
                                 		{  
t1=t1->down;
                                    		while(t1!=NULL)
                                  		 {    
cout<<"\n\t\t\t\tNAME OF SECTION:  "<<t1->name;
                                         			 t2=t1;
                                         			 if(t2->flag==1)
                                         			 {  
t2=t2->down;
                                         				 while(t2!=NULL)
                                          				{     
cout<<"\n\t\t\t\t\t\tNAME OF SUBSECTION:  "<<t2->name;     
                                         					 t2=t2->next;
                                       				   }
                                          			}     
                                      			    t1=t1->next;
                                    		}
                               		  }   
                                 		 temp=temp->next;
                         		  }
                        
                        	  }
                }          
}                  

int main()
{    
        Gll g;
        int x;  
       	while(1)
     	 {    
                       cout<<"\n\n enter your choice";
           	       cout<<"\n 1.insert book";
           	       cout<<"\n 2.insert chapter";
            	       cout<<"\n 3.insert section";
            	       cout<<"\n 4.insert subsection";
            	       cout<<"\n 5.display book";
            	       cout<<"\n 6.exit";
            	       cin>>x;
         		  switch(x)
          		 {   
                        case 1:          g.insertb();
                                          break;             
                	case 2:          g.insertc();
                                          break;      
                	case 3:          g.inserts();
                                          break;
                	case 4:          g.insertss();
                                           break;    
                	case 5:          g.displayb();
                                           break;      
              	        case 6:          exit(0);
           		}
      	 }
       	return 0;
}
