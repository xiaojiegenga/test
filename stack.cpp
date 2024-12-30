#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x) , next(nullptr){};
};

class LinkListStack{
    private:
        ListNode* stack_top;
        int stack_size;
    
    public:
        LinkListStack(){
            stack_top = nullptr;
            stack_size = 0;
        }
        ~LinkListStack(){
            free_memoryLinkedlist(stack_top);
        }
        /*get the size of the stack*/
        int size(){
            return stack_size;
        }
        /*check if the stack is empty*/
        bool is_empty(){
            return stack_size == 0;
        }
        /*push*/
        void push(int val){
            ListNode* node = new ListNode(val);
            node->next = stack_top;
            stack_top = node;
            stack_size++;
        }
        /*pop*/
        int pop(){
            int num = top();
            ListNode* node = stack_top;
            stack_top = stack_top->next;
            delete node;
            stack_size--;
            return num;
        }
        /*get the top element*/
        int top(){
            if(is_empty())
                throw "Stack is empty";
            return stack_top->val;
        }
        /*free the memory of the linked list*/
        void free_memoryLinkedlist(ListNode* node){
            if(node == nullptr)
                return;
            free_memoryLinkedlist(node->next);
            delete node;
        }
        /*print the stack*/
        void print_stack(){
            ListNode* node = stack_top;
            while(node != nullptr){
                cout << node->val << "|" << endl;
                node = node->next;
            }
        }
        /*get the stack as a linked list*/
        vector<int> to_vector(){
            ListNode* node = stack_top;
            vector<int> res(size());
            for(int i = 0; i < size(); i++){
                res[i] = node->val;
                node = node->next;
            }
            return res;
        }
};

int main(void)
{
    LinkListStack s;
    s.push(1);
    s.push(2);
    s.push(3);    
    s.push(4);
    s.push(5);
    s.print_stack();
    cout << "Size of the stack: " << s.size() << endl;
    cout << "Top element of the stack: " << s.top() << endl;
    s.pop();
    s.print_stack();
    cout << "Size of the stack: " << s.size() << endl;

}