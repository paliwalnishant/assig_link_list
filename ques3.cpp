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
};

/////////////////////////// class for linlist
class CLinklist
{
private:

    node *head;
    int length;
    node *create_Node(int val);
public:
    CLinklist()
    {
        head=NULL;
        length=0;
    }
    ~CLinklist()
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
node * CLinklist::create_Node(int val)
{
    node *temp=new node;
    temp->next=NULL;
    temp->data=val;
    return temp;
}
void CLinklist::add_node_at_begning(int val)
{

    node *temp =create_Node(val);
    node *t;

    if(head==NULL)
    {
        head=temp;
        head->next=head;
    }
    else
    {
        temp->next=head;
        t=head;
        while(t->next!=head)
        t=t->next;
        t->next=temp;
        head=temp;
    }
    length++;
}
void CLinklist::add_node_at_last(int val)
{
    node *temp=create_Node(val);
    node *t=head;
    while(t->next!=head)
    t=t->next;
    t->next=temp;
    temp->next=head;
    length++;
}
void CLinklist::display()
{
    node *temp=head;
    cout<<"Display using next pointer: \n\n";
    while(temp->next!=head)
    {
        cout<<temp->data<<" --> ";
        temp=temp->next;
    }
    cout<<temp->data<<"-->"<<"Head";

}
void CLinklist::add_node_at_given_pos(int val,int pos)
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
        //t->next->pre=temp;
        t->next=temp;
//        temp->pre=t;
    }

}
void CLinklist::delete_node_at_begning()
{
    node *temp=head;
    node *t=head;
    while(t->next!=head)
    t=t->next;
    head=head->next;
    t->next=head;
    length--;
    delete(temp);
}
void CLinklist::delete_node_at_last()
{
    node *t=head;
    while(t->next->next!=head)
    t=t->next;
    delete(t->next);
    t->next=head;
    length--;
}
void CLinklist::delete_node_at_given_pos(int pos)
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
//       p->pre=t;
       length--;
    }

}

void CLinklist::update(int new_val,int pos)
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
    CLinklist *ll=new CLinklist();
    ll->add_node_at_begning(1);
    ll->add_node_at_begning(2);
    ll->add_node_at_begning(3);
    ll->add_node_at_begning(4);
    ll->add_node_at_begning(5);

    ll->add_node_at_last(6);

    ll->add_node_at_last(7);


   ll->add_node_at_given_pos(16,3);
   //ll->display();
 //ll->delete_node_at_given_pos(3);
    //ll->update(12,2);
  //ll->reverse();

   //ll->delete_node_at_begning();
    //ll->delete_node_at_last();
    ll->display();


    return 0;

}

