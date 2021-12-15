#include <iostream>

using namespace std;
class Node{

public:
    int data;
    Node *next;

};

class LinkedList{

Node *head=NULL,*current=NULL;
public:
    Node* createNode(int value){
    Node *temp=new Node();
    temp->data=value;
    temp->next=NULL;
    return temp;

  }

   void inserAtFirst(int  value){
   Node *temp=createNode(value);

   if(head==NULL){
    head=temp;
    current=temp;
   }
   else{
    temp->next=head;
    head=temp;
   }

   }

   void insertAtLast(int  value){
        Node *temp=createNode(value);

   if(head==NULL){
    head=temp;
    current=temp;
   }
   else{
    current->next=temp;
    current=current->next;

   }
   }
 int searchV(int searchvalue){
       int  flag=0;
    Node *p=head;
    while(p!=NULL){
    if(p->data==searchvalue)
                {
                   flag=1;
                   break;


                }
    else{

           p=p->next;
           continue;

    }

   }
   return flag;
   }

   void insertAfterValue(int value,int searchValue){

     Node *temp=createNode(value);
        if(head==NULL)
        {
            head=temp;
            current=temp;
        }
        else
        {

   Node *p=head;

   while(p!=NULL){
   if(p->data==searchValue)
                {
                    temp->next=p->next;
                    p->next=temp;
                    break;
                }
    else{
           p=p->next;


    }
   }


   }
   }

    void deleteAtFirst(){
    Node *p=head;
    head=head->next;
    delete p;
    }

    void deleteAtLast(){
    Node *temp=head,*p;
    while(temp->next->next!=NULL){
       temp=temp->next;
     }
     p=temp->next;
     temp->next=NULL;
     delete p;

    }
    void deleteSearch(int searchvalue){
    Node *temp=head,*p;

    while(temp->next->data!=searchvalue){
        temp=temp->next;
    }
    p=temp->next;
    temp->next=temp->next->next;
    delete p;



    }
   void display(){

   Node *p=head;
   while(p!=NULL){
    cout<<p->data<<"->";
    p=p->next;
   }
   cout<<endl;
   }

};
int main()
{
    LinkedList lst;
    bool repeat=true;;
    int input;
    int value;
    int searchValue;

  while(repeat){

       cout<<"1.Insert Value In Node "<< endl;
       cout<<"2.Delete Value from Node "<<endl;
       cout<<"3.Display "<<endl;
       cout<<"4.Exit "<<endl;
        cin>>input;
    switch(input){

case 1:
     cout<<"1.Insert At First "<<endl;
    cout<<"2.Insert At Last "<<endl;
    cout<<"3.Insert After Value "<<endl;
     cin>>input;
    switch(input){

    case 1:
          cout<<"Insert At First: ";
          cin>>value;
           lst.inserAtFirst(value);
            break;

    case 2:
          cout<<"Insert At Last: ";
          cin>>value;
          lst.insertAtLast(value);
            break;

    case 3:
        cout<<"Insert search value: ";
        cin>>searchValue;
       int  ss;
       ss=lst.searchV(searchValue);
        if(ss!=0){
            cout<<"Insert After Value: ";
          cin>>value;
           lst.insertAfterValue(value,searchValue);
          break;
        }
        else{
         cout<<"Not found "<<endl;
         }
            break;

    default :
         cout << "Invalid " << endl;

    }
     break;


case 2:

    cout<<"1.Delete At First "<<endl;
    cout<<"2.Delete At Last "<<endl;
    cout<<"3.Delete Search Value "<<endl;
     cin>>input;
    switch(input){

    case 1:
         cout<<"Deleting At First "<<endl;
         lst.deleteAtFirst();
          break;
    case 2:
         cout<<"Deleting  At Last"<<endl;
         lst.deleteAtLast();
          break;
    case 3:
         cout<<"Insert Your Delete Value:  ";
         cin>>searchValue;
          int  s;
         s=lst.searchV(searchValue);
        if(s!=0){
           lst.deleteSearch(searchValue);
           cout<<"Insert Value Deleted "<<endl;
          break;
        }
        else{

            cout<<"Not found "<<endl;

            }

          break;
      default :
         cout << "Invalid " << endl;

         }
         break;

case 3:

        lst.display();
          break;


case 4:
     cout<<"You have chose to Exit "<<endl;
        repeat= false;
         break;
     default :
         cout << "Invalid " << endl;



    }



  }





    return 0;
}
