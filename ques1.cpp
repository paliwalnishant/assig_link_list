/*
This ques have -insertion in singly linklist delteion update and reverse the linklist.
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
class Linklist
{
private:

    node *head;
    int length;
    node *create_Node(int val);
public:
    Linklist()
    {
        head=NULL;
        length=0;
    }
    ~Linklist()
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
node * Linklist::create_Node(int val)
{
    node *temp=new node;
    temp->next=NULL;
    temp->data=val;
    return temp;
}
void Linklist::add_node_at_begning(int val)
{

    node *temp =create_Node(val);

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    length++;
}
void Linklist::add_node_at_last(int val)
{
    node *temp=create_Node(val);
    node *t=head;
    while(t->next!=NULL)
    t=t->next;
    t->next=temp;
    length++;
}
void Linklist::display()
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}
void Linklist::add_node_at_given_pos(int val,int pos)
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
        t->next=temp;
    }

}
void Linklist::delete_node_at_begning()
{
    node *temp=head;
    head=head->next;
    length--;
    delete(temp);
}
void Linklist::delete_node_at_last()
{
    node *t=head;
    while(t->next->next!=NULL)
    t=t->next;
    delete(t->next);
    t->next=NULL;
    length--;
}
void Linklist::delete_node_at_given_pos(int pos)
{
    if(pos>length+1)
     cout<<"Error:Linklist size is small..\n";
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
     node *  p=t->next->next;
       delete(t->next);
       t->next=p;
       length--;
    }

}

void Linklist::update(int new_val,int pos)
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
void Linklist:: reverse()
{
    node *temp=NULL;
    node *t=head;
    node *p=t->next;
    while(p!=NULL)
    {
        t->next=temp;
        temp=t;
        t=p;
        p=p->next;
    }
    t->next=temp;
    head=t;


}
int main()
{
    Linklist *ll=new Linklist();
    ll->add_node_at_begning(1);
    ll->add_node_at_begning(2);
    ll->add_node_at_begning(3);
    ll->add_node_at_last(4);

    ll->add_node_at_last(5);
    ll->add_node_at_given_pos(16,3);
    ll->delete_node_at_given_pos(2);
    ll->update(12,2);
  ll->reverse();

   // ll->delete_node_at_begning();
    //ll->delete_node_at_last();

    ll->display();
    return 0;

}
