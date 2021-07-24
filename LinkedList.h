#ifndef BSL_LINKED_LIST
#define BSL_LINKED_LIST

namespace BSL
{

	/// <summary>
	/// A linked list implementation.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<class T> class LinkedList
	{
	private:
		struct Node
		{
			T value;
			Node* next;
		};

		Node* root;
		Node* highest;
		Node* lowest;
		unsigned int length = 0;

	public:
		
		/// <summary>
		/// Adds a value to the begining of the linked list.
		/// </summary>
		/// <param name="value">The value to be added.</param>
		void addFirst(T value)
		{
			// Node to add to the linked list.
			Node* toAdd = new Node;
			toAdd->value = value;
			toAdd->next = nullptr;

			// Checks if there is a root.
			if (!length)
			{
				this->root = toAdd;
				this->highest = this->root;
				this->lowest = this->root;
			}
			else
			{
				// Gets root, sets new root, and make pointer of new root to the old root.
				Node* oldRoot = this->root;
				this->root = toAdd;
				toAdd->next = oldRoot;
			}

			this->length++;
		}

		/// <summary>
		/// Adds a value to the end of the linked list.
		/// </summary>
		/// <param name="value">Value to be added to the end of the linked list.</param>
		void addLast(T value)
		{
			Node* toAdd = new Node;
			toAdd->value = value;
			toAdd->next = nullptr;

			if (!length)
			{
				this->root = toAdd;
				this->highest = this->root;
				this->lowest = this->root;
			}
			else
			{
				this->highest->next = toAdd;
				this->highest = toAdd;
			}
			
			this->length++;
		}

		/// <summary>
		/// Gets specified value from linked list.
		/// </summary>
		/// <param name="index">The index of the element to get.</param>
		/// <returns>Returns the value at the index.</returns>
		T get(unsigned int index)
		{
			// Loops through the linked list until right element is found.
			Node* currentNode = root;

			unsigned int i = 0;
			while (i != index)
			{
				currentNode = currentNode->next;
				i++;
			}
			
			return currentNode->value;
		}

		/// <summary>
		/// Sets value of specific element in linked list.
		/// </summary>
		/// <param name="index">The index of the variable to change.</param>
		/// <param name="value">The value to replace it with.</param>
		void set(unsigned int index, T value)
		{
			// Loops through the linked list until right element is found.
			Node* currentNode = root;

			int i = 0;
			while (i != index)
			{
				currentNode = currentNode->next;
				i++;
			}

			currentNode->value = value;
		}

		/// <summary>
		/// Removes the node at index.
		/// </summary>
		/// <param name="index">The index of the node to remove.</param>
		void remove(unsigned int index)
		{
			// Checks if root node is to be removed.
			if (index == 0)
			{
				Node* oldRoot = this->root;
				this->root = this->root->next;	// Makes second node root node.
				delete oldRoot;
			}
			else
			{
				Node* previous = root;
				Node* currentNode = root;

				int i = 0;
				while (i != index)
				{
					currentNode = currentNode->next;
					i++;
				}

				// Sets previous node to index of currentNode - 1.
				for (int j = 0; j < i - 1; j++)
				{
					previous = previous->next;
				}

				previous->next = currentNode->next;
				delete currentNode;
			}
			this->length--;
		}

		/// <summary>
		/// Gets length of the linked list.
		/// </summary>
		/// <returns>Returns the length of the linked list.</returns>
		unsigned int getLength()
		{
			return length;
		}

		/// <summary>
		/// Checks if linked list is empty.
		/// </summary>
		/// <returns>Returns a boolean; true if length is 0</returns>
		bool isEmpty()
		{
			return (this->length == 0);
		}
	};
}
#endif // !LINKED_LIST