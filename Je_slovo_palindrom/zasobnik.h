
#include <iostream>
#include <stack>

class Stack {
		struct Tstruct { char value; Tstruct* next; };

		Tstruct* TOP;

	public:
		Stack() {
			TOP = NULL;
		}

		void Push(char VALUE) { // helping pointer 
			Tstruct* l_hlp; // try to allocate the memory 
			try
			{
				l_hlp = new Tstruct;
			}
			catch (const std::bad_alloc& e) {
				throw std::runtime_error(e.what());
			} // new member points to the recent 

			l_hlp->next = TOP; //store value l_hlp->value = VALUE; // new member becomes new TOP TOP = l_hlp;
			l_hlp->value = VALUE;
			TOP = l_hlp;

		}

		// Pop - pops and returns value from the top of the stack 
		char Pop() {
			if (TOP == NULL) {
				throw std::runtime_error("Stack is empty");
				return 0;
			} // helping variables 
			Tstruct* l_hlp;
			int l_val; // store pointer to the TOP 
			l_hlp = TOP; // TOP points to the following element 
			TOP = l_hlp->next; //store value from the TOP 
			l_val = l_hlp->value; // delete previous TOP 
			delete l_hlp; // returns the value from previous TOP 
			return l_val;
		}

		// Show - returns value from the top of the stack // without poping it 
		char Show() {
			if (TOP) {
				return TOP->value;
			}
			else {
				throw std::runtime_error("Stack is empty");
				return 0;
			}

		};

		//IsEmpty - returns true/false if the stack is/is not //empty 
		bool IsEmpty() {
			return !bool(TOP);
		};

		//Empty - empties the stack 
		void Empty() {
			while (!IsEmpty()) Pop();
		};

		// destructor - destroys whole structure 
		~Stack() {
			Empty();
			delete(TOP);
		};
	};





