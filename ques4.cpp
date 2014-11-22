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
    void display();
    void kth_last_element(int k);

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
void Linklist::kth_last_element(int k)
{
    node *t1=head,*ans=head;
    int     count=0;
    while(t1!=NULL)
    {
        t1=t1->next;
        count++;
        if(count==k-1)
        {
           ans=ans->next;
           count=0;
        }
    }
    cout<<"\n"<<k<<"'th element from last:"<<ans->data;
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
    ll->display();
    ll->kth_last_element(4);
    return 0;

}

