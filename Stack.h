#ifndef BSL_STACK
#define BSL_STACK

namespace BSL
{
	/// <summary>
	/// Class used to make a stack data structure.
	/// </summary>
	/// <typeparam name="T">Type of the data it holds.</typeparam>
	template<class T> class Stack
	{
	private:
		struct Node
		{
			T value;
			Node* below;
		};

		Node* root;
		Node* top;
		unsigned int length = 0;

	public:
		/// <summary>
		/// Pushes a item on the stack.
		/// </summary>
		/// <param name="value">The value of the item.</param>
		void push(T value)
		{
			if (length == 0)
			{
				Node* toAdd = new Node;
				toAdd->value = value;
				toAdd->below = nullptr;

				this->root = toAdd;
				this->top = toAdd;
			}
			else
			{
				Node* toAdd = new Node;
				toAdd->value = value;
				toAdd->below = this->top;

				this->top = toAdd;
			}

			this->length++;
		}

		/// <summary>
		/// Pops the highest item of the list.
		/// </summary>
		/// <returns>Returns the item it popped of.</returns>
		T pop()
		{
			T ret = this->top->value;
			Node* toDelete = this->top;
			this->top = this->top->below;
			this->length--;
			delete toDelete;
			return ret;
		}

		/// <summary>
		/// Peek returns the value of the highest item without popping it.
		/// </summary>
		/// <returns>Returns value of highest element.</returns>
		T peek()
		{
			return this->top->value;
		}

		/// <summary>
		/// Returns true or false depending on if the stack is empty.
		/// </summary>
		/// <returns>Returns true or false.</returns>
		bool isEmpty()
		{
			return this->length == 0;
		}

		/// <summary>
		/// Get the size of the stack.
		/// </summary>
		/// <returns>Returns the size/length of the stack.</returns>
		unsigned int getSize()
		{
			return this->length;
		}
	};
}

#endif // !BSL_STACK