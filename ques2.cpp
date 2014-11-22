/*
This ques have -insertion in Doubly linklist delteion update and reverse the linklist.
*/
#include<iostream>
using namespace std;
///////////////// structure for node
struct node
{
  int data;
  struct node *next;
  struct node *pre;
};

/////////////////////////// class for linlist
class DLinklist
{
private:

    node *head;
    int length;
    node *create_Node(int val);
public:
    DLinklist()
    {
        head=NULL;
        length=0;
    }
    ~DLinklist()
    {
        delete(head);
    }
       /* insertion */
    void add_node_at_begning(int val);
    void add_node_at_last(int val);
    void add_node_at_given_pos(int val,int pos);
       /* deletion */
    void delete_node_at_begning();
    void delete_node_at_last();
    void delete_node_at_given_pos(int pos);
       /* update*/
    void update(int new_val,int pos);
      /*reverse */
    void reverse();
      /* display*/
    void display();

};
node * DLinklist::create_Node(int val)
{
    node *temp=new node;
    temp->next=temp->pre=NULL;
    temp->data=val;
    return temp;
}
void DLinklist::add_node_at_begning(int val)
{

    node *temp =create_Node(val);

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head->pre=temp;
        head=temp;
    }
    length++;
}
void DLinklist::add_node_at_last(int val)
{
    node *temp=create_Node(val);
    node *t=head;
    while(t->next!=NULL)
    t=t->next;
    t->next=temp;
    temp->pre=t;
    length++;
}
void DLinklist::display()
{
    node *temp=head,*temp1;
    cout<<"Display using next pointer: \n\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<" <--> ";
        temp1=temp;
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";
    cout<<"Display using pre pointer REVERSE LINKLIST:"<<"\n\n";
    while(temp1!=NULL)
    {
        cout<<temp1->data<<" <--> ";
        temp1=temp1->pre;
    }
    cout<<"NULL";


}
void DLinklist::add_node_at_given_pos(int val,int pos)
{
    if(pos>length+1)
     cout<<"Error:Linklist size is small..\n";
    else if(pos==1)
    this->add_node_at_begning(val);
    else if(pos==length+1)
    this->add_node_at_last(val);
    else
    {
        node *temp=create_Node(val);
        int count=1;
        node *t=head;
        while(count+1!=pos)
        {
            t=t->next;
            count++;
        }
        temp->next=t->next;
        t->next->pre=temp;
        t->next=temp;
        temp->pre=t;
    }

}
void DLinklist::delete_node_at_begning()
{
    node *temp=head;
    head=head->next;
    head->pre=NULL;
    length--;
    delete(temp);
}
void DLinklist::delete_node_at_last()
{
    node *t=head;
    while(t->next->next!=NULL)
    t=t->next;
    delete(t->next);
    t->next=NULL;
    length--;
}
void DLinklist::delete_node_at_given_pos(int pos)
{
    if(pos>length+1)
     cout<<"Error:Linklist size is small..\n:";
    else if(pos==1)
    this->delete_node_at_begning();
    else if(pos==length+1)
    this->delete_node_at_last();
    else
    {
        int count=1;
        node *t=head;
        while(count+1!=pos)
        {
            t=t->next;
            count++;
        }
     node *p=t->next->next;
       delete(t->next);
       t->next=p;
       p->pre=t;
       length--;
    }

}

void DLinklist::update(int new_val,int pos)
{
    node *t=head;
    int count=1;
    if(pos>length+1)
    cout<<"Error:Linklist size is small..\n";
    while(count!=pos)
    {
        t=t->next;
        count++;
    }
    t->data=new_val;
}

int main()
{
    DLinklist *ll=new DLinklist();
    ll->add_node_at_begning(1);
    ll->add_node_at_begning(2);
    ll->add_node_at_begning(3);
    ll->add_node_at_last(4);

    ll->add_node_at_last(5);

    ll->add_node_at_given_pos(16,3);
    //ll->delete_node_at_given_pos(2);
    //ll->update(12,2);
  //ll->reverse();

   //ll->delete_node_at_begning();
    ll->delete_node_at_last();

    ll->display();
    return 0;

}
